import matplotlib
import matplotlib.pyplot as plt
import sys
import os

# Pathname
dir_path = os.path.dirname(os.path.realpath(__file__))

# Config variables
step = 10
maximum = 800
height = 600
width = 1800
measuresData = range(1, maximum + 1, step)

if (len(sys.argv) == 1):
    print("You need provide pathname: (*.txt)")
    exit()

try:
    pathname = dir_path + sys.argv[1]
    f = open(pathname, "r")
except OSError:
    print(dir_path)
    print(sys.argv[1:])
    print("Error opening the file, verify and try again, please.")
    exit()

# Read data from file
mergeMeasures = []
insertionMeasures = []
lines = f.readlines()
for line in lines:
    measures = line.split(" ")
    insertionMeasures.append(float(measures[0]))
    mergeMeasures.append(float(measures[1]))

# Plot merge measures
plt.plot(measuresData, mergeMeasures, linewidth=4.0, label='Merge')

# Plot insertion measures
plt.plot(measuresData, insertionMeasures, linewidth=2.0, label='Insertion', linestyle='dashed')

# Custom graph
plt.ylabel('seconds')
plt.xlabel('collection\'s length')
plt.legend()

# Save graph
fig = plt.gcf()
DPI = fig.get_dpi()
fig.set_size_inches(width/float(DPI), height/float(DPI))
plt.savefig(dir_path + '/output/insertion_vs_merge_sort.png')

# End
print("Grafico generado correctamente")
exit()
