while True:
    with open("output.txt") as fp:
        for i, line in enumerate(fp):
            if i == 9600:
                if float(line) < 100.00:
                    print("No fever detected.")
                else:
                    print("Fever detected.")

    