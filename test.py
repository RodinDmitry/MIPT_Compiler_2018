import os
import sys
import subprocess

_, executable, test_folder, result_folder = sys.argv

for file in os.listdir(test_folder):
    test_file = test_folder + file
    result_file = result_folder + file
    subprocess.check_call([executable, "--ename", result_file, test_file])
