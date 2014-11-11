
import re

#filename = './fm2d.m'
filename = './rtm2d.m'

with open(filename) as fi:
  content = fi.read()
  r = re.sub(r'(fdm\(.*?,.*?,).?([123])\)', r'\1fdm\2)', content)
  print r


with open(filename, 'w') as fi:
  fi.write(r)
