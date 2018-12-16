import os
import sys
import subprocess

executable = 'MIPT_Compiler/x64/Debug/Analyzer.exe'
good_test_folder = 'Samples/'
bad_test_folder = 'BadSamples/'
result_folder = 'Results/'

def process_folder(folder):
	if not os.path.exists(result_folder + folder):
		os.mkdir(result_folder + folder)
	print_file = result_folder + folder + 'graph.txt'
	for file in os.listdir(folder):
		test_file = folder + file
		result_file = result_folder + folder + file[:-5] + '.txt'
		pr_file = result_file[:-4] + ".svg"
		subprocess.check_call([executable, "--ename", result_file, "--irname", print_file, test_file])
		if not 'Bad' in folder:
			subprocess.check_call(["dot", "-Tsvg", "-o", pr_file, print_file])

process_folder(good_test_folder)
process_folder(bad_test_folder)
