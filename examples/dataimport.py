import sys
from os import path

fevercount = 0
nonfevercount = 0



countthreshold = 5
tempthreshold = 100.00

#variables manipulated by other python scripts
getdataflag = 1
pixeldata = [1000,2000,3000,4000,5000]

j = 0

while getdataflag == 1:
    with open("C:\\Users\\ptssm\\Documents\\GitHub\\leptonic\\examples\\output.txt") as fp:
        for i, line in enumerate(fp):
            if i == pixeldata[j]:
                if float(line) < tempthreshold:
                    nonfevercount = nonfevercount + 1
                else:
                    fevercount = fevercount + 1

                if j < len(pixeldata):
                    j = j + 1
                else:
                    j = 0

                if fevercount == countthreshold:
                    print("Fever detected.")
                    fevercount = 0
                    nonfevercount = 0
                    getdataflag = 0
                    j = 0
                elif nonfevercount == countthreshold:
                    print("No fever detected.")
                    fevercount = 0
                    nonfevercount = 0
                    getdataflag = 0
                    j = 0
