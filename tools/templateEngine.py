import fileinput
import sys
from string import Template

prj = sys.argv[1]

d = dict(project=prj)

tpl = open(sys.argv[2])

src = Template(tpl.read())

f = open(sys.argv[3], "w")

f.write(src.substitute(d))


