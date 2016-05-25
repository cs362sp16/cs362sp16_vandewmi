import subprocess
import os
import sys

os.system("make " + sys.argv[1] + "/testdominion 2> /dev/null")
os.system("make " + sys.argv[2] + "/testdominion 2> /dev/null")
os.system(sys.argv[1] + "/testdominion " + sys.argv[3] + " > diffout1 2> /dev/null")
os.system(sys.argv[2] + "/testdominion " + sys.argv[3] + " > diffout2 2> /dev/null")

diff_proc = subprocess.Popen(["diff", "diffout1", "diffout2"], stdout=subprocess.PIPE)
diff, err = diff_proc.communicate()

if diff == "":
	print "TEST PASSED"
	print diff
else:
	print "TEST FAILED"
	print diff
