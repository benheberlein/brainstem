import fileinput
import sys

flag = 0;

for line in fileinput.input(sys.argv[1], inplace=True):
    line = line.replace('#include "faust', '//#include "faust')

    if line.find("UIGlue") != -1:
        flag = 1
    if line.find("MetaGlue") != -1:
        flag = 1
    if line.find("main") != -1:
        flag = 1

    if flag == 1:
        line = "//" + line
        if line.find("}") != -1:
            flag = 0

    if line.find("mydsp") != -1:
        line = "//" + line

    sys.stdout.write(line);
