# File name: tme.py
# Created by Norman Matloff
#
# reads in the text file whose name is specified on the command line,
# and reports the number of lines and words
import sys
import csv
infile = open(sys.argv[1])
reader = csv.reader(infile)
headings = []
headings = next(reader)
rows = []

for line in reader:
	rows.append(float(line[1]))
	print(rows)

