with open("./names.csv") as f:
    for i,n in enumerate(f.readlines()):
        print(f"Nom de l'equipier no{i}:", n[:-1])
