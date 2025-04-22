# File name: tme.py
# Created by Norman Matloff
#
# reads in the text file whose name is specified on the command line,
# and reports the number of lines and words
import sys
import csv

def average(list):
	length = len(list)
	sum  = 0
	for i in range(length):
		sum = sum + list[i]
	avg = sum/length
	return avg

def minimum(list):
	length = len(list)
	min = list[0]
	for i in range(length):
		if list[i] < min:
			min = list[i]
	return min


def maximum(list):
        length = len(list)
        max = list[0]
        for i in range(length):
                if list[i] >  min:
                        max = list[i]
        return max


infile = open(sys.argv[1])
reader = csv.reader(infile)
headings = []
headings = next(reader)
rows = []

for line in reader:
	rows.append(float(line[1]))

print(average(rows))
print(min(rows))
print(max(rows))
