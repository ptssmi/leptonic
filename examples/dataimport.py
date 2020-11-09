
with open("output.txt") as fp:
    for i, line in enumerate(fp):
        if i == 25:
            if float(line) < 100:
                print("No fever detected.")
            else:
                print("Fever detected.")

    