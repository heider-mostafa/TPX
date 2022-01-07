# TPX

Ce repo sert de modèle pour tous les autres devoirs de la session. Il vise à vous familiariser avec la structure attendue. Il introduit aussi des concepts importants de contrôle de versions et de Unix.

# Git

Git sera utilisé tout au long du cours. Git peut sembler un peu intimidant, mais pour nos fins, c'est un logiciel assez simple. Voici les commandes dont vous aurez besoin:

- Pour commencer, vous pouvez cloner ce repo avec `git clone <url du repo>`
- Si vous ajoutez un fichier au repo, vous pouvez l'ajouter avec `git add <path relatif du fichier>`
- Vous pouvez inclure vos changements à votre historique git en faisant `git commit -a -m "<un message explicatif>"`. Vous devez faire ceci après avoir changé un fichier, ou en avoir ajouté un nouveau avec `git add`. Vous n'êtes pas obligés de le faire après chaque changement, cependant! Vous pouvez le voir comme la fonction "sauvegarde de git", donc appeler cette commande lorsque vous voulez sauvegarder.
- Et finalement, la magie de git: `git push`. Ceci permet de "pousser" vos changements vers le nuage. Il est donc impossible de perdre votre progrès, et il est extrêmement facile de coordonner vos changements avec vos coéquipiers.

Comme git recevra des changements de vous *et* et votre partenaire, il se peut qu'il y ait des conflits entre les versions des fichiers. Vous pouvez utiliser git comme une bonne vieille clé USB, et ne jamais travailler en même temps (pour éviter les conflits), mais il serait très important pour votre croissance en tant que programmeur d'apprendre à gérer ces conflits avec git. Il existe des tonnes de guides sur le web.

# Unix

Unix est utilisé pour tout ce cours. Pourquoi pas Windows? Windows n'offre aucune option open-source, ce qui est déjà très peu désirable pour le milieu de recherche qu'est l'université. Windows utilise aussi des librairies C très différentes de celles de Linux et de MacOS. Windows est aussi payant, alors que Linux est gratuit est facile d'accès pour tout le monde. Si votre machine roule seulement Windows, il est facile de la partitionner et d'installer linux sur une des partitions, ou même d'installer linux sur une clé USB. De plus, Linux est facile à installer dans une machine virtuelle ou même nativement avec le Windows Subsystem for Linux (WSL2).
La programmation bas niveau est très capricieuse. Il est important que tous les systèmes soient le plus similaire possible entre la machine de l'étudiant et celle des correcteurs. Vous devez vous assurez que votre code roule bien sur les ordinateurs Linux du DIRO, que vous ayez codé votre code sur Windows, MacOS, ou même Linux.
Si on réfère au "terminal" à n'importe quel endroit dans les exercices du cours, on réfère au terminal de Linux.


# Correction Automatique

Tous les devoirs de la session seront corrigés automatiquement très vaste partie. Il est donc **_extrêmement_** important que vous respectiez les formats attendus. Lisez bien les consignes.

# `names.txt`

Ce fichier contiendra les noms et matricules de l'équipe. L'exemple fournis ici contient le nom des deux démos du cours, Charlie Gauthier et Samuel Yvon.

N'incluez rien d'autre que vos noms. Pas de commentaires, pas de email, de notes, etc. Chaque prénom-nom-matricule doit aller sur une ligne chaque, comme dans l'exemple. **_Écrivez le même nom qui paraît sur Studium._**

Important! On veut votre *matricule*, pas votre code de connection sur synchro qui commence par un 'p'.

Si vous avez des caractères non-ascii dans votre nom, il se peut que l'ouput du name-validator soit un peu brisé. Ce n'est pas grave: c'est votre matricule qui est importante.

# `name_validator.py`

Vous pouvez vérifier que votre fichier est du bon format en roulant `name_validator.py`.

Pour ce faire, simplement écrire `python3 name_validator.py` dans votre terminal.

# `src`

Le dossier `src` contiendra tout votre code C.

# `src/CMakeLists.txt`

Ce fichier défini le projet sur lequel vous travaillez. Ceci permet à un IDE comme [CLion](https://www.jetbrains.com/clion/) de contrôler un débuggeur, d'indexer votre projet, etc. Normalement, vous n'aurez pas à toucher à ce fichier, et ce, pour tous les travaux de la session.

# `src/main.c`

Ce fichier est le point d'entrée de votre projet. Dans la vaste majorité des cas, ce sera le seul fichier C utilisé dans le projet. **_N'ajoutez pas de fichier C ou .h! Nous ne compilerons que ceux déjà présents dans le repo que vous recevez comme devoir!_**

Pour certains devoirs, nous allons devoir arracher votre fonction `main`. Donc soyez averties que TOUT le code qui se trouve entre deux balises `// ༽つ۞﹏۞༼つ` sera enlevé. (Le nom de ce bel homme `// ༽つ۞﹏۞༼つ**` est "Jeff", en passant.) N'enlevez **jamais** Jeff de vos travaux, sinon l'autograder va briser pour votre TP.

# `test`

Ce dossier contient des fichiers des test. Il se peut qu'il soit vide.

**_NE MODIFIEZ PAS CE DOSSIER_**

**Il n'y a AUCUNE garantie que votre fichier `test` soit complet. Autrement dit, il est FORT PROBABLE que nous ajoutions des tests après la date de remise! Codez en conséquence.**

# Github Classroom

Github classroom nous permet de corriger vos TPs automatiquement. Pour savoir votre note, il suffit de cliquer sur le petit checkmark vert ✅ dans la barre d'information de commits de votre repository. 

![image](https://user-images.githubusercontent.com/31974070/148586322-3b37e39c-d05c-4189-b354-057488001583.png)

Ensuite, cliquez sur `Run education/autograding`

![image](https://user-images.githubusercontent.com/31974070/148586435-362af704-81f1-4cd2-92ff-1ef736ab15ee.png)

A la toute fin de ce bloc de test, il y aura votre note dans une balise `GRADE:{<note>}`

![image](https://user-images.githubusercontent.com/31974070/148586511-69009f6b-a224-4ae1-8012-42522b058d5b.png)

Ignorez le joli
"""
All tests passed

✨🌟💖💎🦄💎💖🌟✨🌟💖💎🦄💎💖🌟✨
"""

# CLion

Vous pouvez installer cet IDE dès maintenant et essayer de rouler le fichier `src/main.c`! Cet IDE a une intégration avec Valgrind, un programme qui permet de tester votre code pour y trouver des fuites mémoires et des accès mémoires illégaux. C'est gratuit pour les étudiants [https://www.jetbrains.com/community/education/#students](https://www.jetbrains.com/community/education/#students).

# Remise

Ce travail est à faire **en équipe**. Vous pouvez le faire seul, mais la charge de travail ne sera pas amoindrie. 

Le code est à remettre sur Github Classroom (autrement dit,
la dernière version à la date de la remise sera utilisée).

Chaque jour de retard est -15%, mais après le deuxième jour la remise ne
sera pas acceptée.

Indiquez clairement votre/vos noms dans le fichier `names.txt` tel qu'indiqué dans le repo du [TPX](https://github.com/IFT2245/TPX).

Le programme doit être exécutable sur les ordinateurs du DIRO. Assurez-vous que tout fonctionne correctement sur les ordinateurs du
DIRO.

# Barèmes de correction standards

Voici quelques barèmes de correction qui seront standard pour tous les devoirs.

- Tout usage de matériel (code ou texte) emprunté à quelqu’un d’autre
    (trouvé sur le web, etc.) doit être dûment mentionné, sans quoi cela
    sera considéré comme du plagiat. Si pour une question votre solution
    est directement copiée, même si il y a attribution de la source,
    cette question se verra attribuée la note de zéro. Vous pourrez
    cependant l’utiliser dans les sections suivantes sans pénalité.
- Votre devoir sera corrigé automatiquement en très grande partie. Si
    vous déviez de ce qui est demandé en output, les points que vous
    perdrez seront perdus pour de bon. Si vous n’êtes pas certains d’un
    caractère demandé, demandez, et nous répondrons
    de façon à ce que chaque étudiant puisse voir la réponse.
- La méthode de développement recommandée est d’utiliser CLion et son
    intégration avec Valgrind. Si vous voulez utiliser d’autres
    techniques, vous pouvez le faire, mais nous ne vous aiderons si vous
    rencontrez des problèmes avec ces techniques.
- Vous serez pénalisés pour chaque warning lors de la compilation à raison de 1% par warning,sauf pour les warning reliés à l’assignation à NULL, à la comparaison avec NULL, et aux override des fonctions de librairie. Ces 1% peuvent être cumulés jusqu'à 5%.
- Si une fuite mémoire mémoire est identifiée, vous perdrez 15%. Vous ne perdrez pas plus de points pour les fuites si vous en avez une ou trente.
- Les accès mémoire illégaux identifiés par Valgrind entraîneront jusqu’à 5% de perte, à raison de 1% par accès. La répétition d’un même accès sera comptée comme 1% de plus quand même.
