#guesses 148120
#guesses 140108
#guesses 138277

from collections import Counter
import fileinput
import sys
import re

def main():
	sum = 0
	sector_id = 0
	vals = [0] * 5
	for line in fileinput.input():
		check = False
		line = re.split(r'-*\[*]*\n*',line)
		curr_sector_id = int(line[-3])
		checksum = line[-2]
		line = line[:-2]
		line = ''.join(line)
		print("checksum: "+checksum)
		print("line: "+line)
		parse_line(line)
		for i in range(len(checksum)):
			vals[i] = line.count(checksum[i])
			if (vals[i] != 0):
				check = True
			else :
				check = False
				break
		if (check == True):
			if (refine_check(vals,checksum) == True):
				sector_id += curr_sector_id
			else:
				check = False
		print("bool: "+str(check)+"\n")
	print("sector id: " + str(sector_id) + "\n")

def refine_check(vals,checksum):
	bool_yeah = False
	for i in range(1,5):
		if (vals[i] < vals[i-1]):
				bool_yeah = True
		elif (vals[i] == vals[i-1]):	
			sorted_sum = ''.join(sorted(checksum[i-1]+checksum[i]))
			unsorted_sum = ''.join(checksum[i-1]+checksum[i])
			#print("S: "+sorted_sum+" | U: "+unsorted_sum)
			if (sorted_sum == unsorted_sum):
				#print("They are =")
				bool_yeah = True
			else: 
				return False
		else:
			return False
	return bool_yeah

def parse_line(line):
	#must count what has the most reoccurences in it
	#print(collections.Counter(line).most_common(1)[0])
	c_freq = Counter(line)

	print (c_freq)

if __name__ == "__main__":
	main()