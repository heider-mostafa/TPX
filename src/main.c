#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/wait.h>

#define true 1
#define false 0
#define bool int

typedef int error_code;

#define ERROR (-1)
#define HAS_ERROR(code) ((code) < 0)
#define NULL_TERMINATOR '\0'

#define ERROR (-1)
#define HAS_ERROR(code) ((code) < 0)
#define HAS_NO_ERROR(code) ((code) >= 0)

/**
 * Cette fonction compare deux chaînes de caractères.       
 * @param p1 la première chaîne
 * @param p2 la deuxième chaîne
 * @return le résultat de la comparaison entre p1 et p2. Un nombre plus petit que
 * 0 dénote que la première chaîne est lexicographiquement inférieure à la deuxième.
 * Une valeur nulle indique que les deux chaînes sont égales tandis qu'une valeur positive
 * indique que la première chaîne est lexicographiquement supérieure à la deuxième.
 */
int strcmp(const char *p1, const char *p2) {
    char c1, c2;
    do {
        c1 = (char) *p1++;
        c2 = (char) *p2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);
    return c1 - c2;
}

/**
 * Ex. 1: Calcul la longueur de la chaîne passée en paramètre selon
 * la spécification de la fonction strlen standard
 * @param s un pointeur vers le premier caractère de la chaîne
 * @return le nombre de caractères dans le code d'erreur, ou une erreur
 * si l'entrée est incorrecte
 */
error_code strlen2(const char *s) {
    // Vérification de l'entrée
    if (s == NULL) {
        return ERROR;
    }

    // Calcul de la longueur
    size_t length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }

    // Retourne la longueur
    return (error_code)length;
}

/**
 * Ex.2 :Retourne le nombre de lignes d'un fichier sans changer la position
 * courante dans le fichier.
 * @param fp un pointeur vers le descripteur de fichier
 * @return le nombre de lignes, ou -1 si une erreur s'est produite
 */
error_code no_of_lines(FILE *fp) {
    if (fp == NULL) {
        return -1;  // Erreur : pointeur de fichier invalide
    }

    long current_pos = ftell(fp);  // Sauvegarde de la position courante
    if (current_pos == -1) {
        return -1;  // Erreur lors de la récupération de la position
    }

    if (fseek(fp, 0, SEEK_SET) != 0) {
        return -1;  // Erreur lors du déplacement au début du fichier
    }

    int line_count = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }

    if (ferror(fp)) {
        clearerr(fp);
        fseek(fp, current_pos, SEEK_SET);  // Tentative de restauration de la position
        return -1;  // Erreur de lecture
    }

    // Restauration de la position originale
    if (fseek(fp, current_pos, SEEK_SET) != 0) {
        return -1;  // Erreur lors de la restauration de la position
    }

    return line_count;
}

/**
 * Ex.3: Lit une ligne au complet d'un fichier
 * @param fp le pointeur vers la ligne de fichier
 * @param out le pointeur vers la sortie
 * @param max_len la longueur maximale de la ligne à lire
 * @return le nombre de caractère ou ERROR si une erreur est survenue
 */
error_code readline(FILE *fp, char **out, size_t max_len) {
    if (fp == NULL || out == NULL || max_len == 0) {
        return ERROR;
    }

    /* On alloue max_len + 1 octets pour avoir de la place pour le caractère nul '\0'
       à la fin de la chaîne. Cela garantit que la chaîne sera toujours correctement terminée,
       même si on lit max_len caractères. */
    char *buffer = malloc(max_len + 1);
    if (buffer == NULL) {
        return ERROR;  // Échec d'allocation mémoire
    }

    size_t i = 0;
    int c;

    while (i < max_len && (c = fgetc(fp)) != EOF && c != '\n') {
        buffer[i++] = (char)c;
    }

    if (i == 0 && c == EOF) {
        free(buffer);
        *out = NULL;
        return ERROR;  // Aucun caractère lu et fin de fichier atteinte
    }

    buffer[i] = '\0';  // Ajouter le caractère nul de fin de chaîne

    *out = buffer;  // Affecter la bonne valeur à out

    return (error_code)i;  // Retourner le nombre de caractères lus
}
/**
 * Ex.4: Copie un bloc mémoire vers un autre
 * @param dest la destination de la copie
 * @param src  la source de la copie
 * @param len la longueur (en byte) de la source
 * @return nombre de bytes copiés ou une erreur s'il y a lieu
 */
error_code memcpy2(void *dest, const void *src, size_t len) {
    // Vérification des paramètres d'entrée
    if (dest == NULL || src == NULL) {
        return ERROR;
    }

    // Cas particulier : si len est 0, rien à copier
    if (len == 0) {
        return 0;
    }

    // Conversion des pointeurs en unsigned char* pour manipulation byte par byte
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // Vérification du chevauchement des zones mémoire
    if ((d < s && d + len > s) || (s < d && s + len > d)) {
        return ERROR;  // Chevauchement détecté
    }

    // Copie byte par byte
    for (size_t i = 0; i < len; i++) {
        d[i] = s[i];
    }

    return (error_code)len;  // Retourne le nombre de bytes copiés
}

/**
 * Ex.5: Analyse une ligne de transition
 * @param line la ligne à lire
 * @param len la longueur de la ligne
 * @return la transition ou NULL en cas d'erreur
 */
transition* parse_line(char* line, size_t len) {
    if (line == NULL || len == 0) {
        return NULL;
    }

    // Allouer la mémoire pour la structure transition
    transition* trans = (transition*)malloc(sizeof(transition));
    if (trans == NULL) {
        return NULL;
    }

    // Initialiser les pointeurs à NULL pour faciliter la gestion des erreurs
    trans->current_state = NULL;
    trans->next_state = NULL;

    // Variables pour parser la ligne
    char *start = line;
    char *end = line;
    int field = 0;

    while (*end != '\0' && field < 5) {
        // Trouver la fin du token (espace ou fin de chaîne)
        while (*end != ' ' && *end != '\0') {
            end++;
        }

        // Sauvegarder temporairement le caractère à la fin du token
        char temp = *end;
        *end = '\0';

        // Calculer la longueur du token
        error_code token_len = strlen2(start);
        if (token_len < 0) goto error;

        // Traiter le token selon sa position
        switch (field) {
            case 0: // current_state
                trans->current_state = (char*)malloc(token_len + 1);
                if (trans->current_state == NULL) goto error;
                memcpy2(trans->current_state, start, token_len + 1);
                break;
            case 1: // next_state
                trans->next_state = (char*)malloc(token_len + 1);
                if (trans->next_state == NULL) goto error;
                memcpy2(trans->next_state, start, token_len + 1);
                break;
            case 2: // movement
                trans->movement = start[0];
                break;
            case 3: // read
                trans->read = start[0];
                break;
            case 4: // write
                trans->write = start[0];
                break;
        }

        // Restaurer le caractère
        *end = temp;

        // Passer au token suivant
        if (*end != '\0') {
            end++;
            start = end;
        }
        field++;
    }

    // Vérifier si tous les champs ont été remplis
    if (field != 5) goto error;

    return trans;

error:
    // En cas d'erreur, libérer la mémoire allouée et retourner NULL
    if (trans->current_state) free(trans->current_state);
    if (trans->next_state) free(trans->next_state);
    free(trans);
    return NULL;
}

/**
 * Ex.6: Execute la machine de turing dont la description est fournie
 * @param machine_file le fichier de la description
 * @param input la chaîne d'entrée de la machine de turing
 * @return le code d'erreur
 */
error_code execute(char *machine_file, char *input) {
    return ERROR;
}

// ATTENTION! TOUT CE QUI EST ENTRE LES BALISES ༽つ۞﹏۞༼つ SERA ENLEVÉ! N'AJOUTEZ PAS D'AUTRES ༽つ۞﹏۞༼つ

// ༽つ۞﹏۞༼つ

int main() {
// ous pouvez ajouter des tests pour les fonctions ici

    return 0;
}

// ༽つ۞﹏۞༼つ
