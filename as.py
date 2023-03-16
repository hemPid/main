import matplotlib.pyplot as plt
import numpy as np

n_s = []
q_l_append = []
q_l_pop = []
q_d_append = []
q_d_pop = []
q_c_append = []
q_c_pop = []

with open('q_l_append.txt', 'r') as f:
	for line in f:
		spl = line.rstrip().split(" : ")
		n_s.append(int(spl[0]))
		q_l_append.append(float(spl[1]))

with open('q_l_pop.txt', 'r') as f:
	for line in f:
		spl = line.rstrip().split(" : ")
		q_l_pop.append(float(spl[1]))


with open('q_d_append.txt', 'r') as f:
	for line in f:
		spl = line.rstrip().split(" : ")
		q_d_append.append(float(spl[1]))

with open('q_d_pop.txt', 'r') as f:
	for line in f:
		spl = line.rstrip().split(" : ")
		q_d_pop.append(float(spl[1]))

with open('q_c_append.txt', 'r') as f:
	for line in f:
		spl = line.rstrip().split(" : ")
		q_c_append.append(float(spl[1]))

with open('q_c_pop.txt', 'r') as f:
	for line in f:
		spl = line.rstrip().split(" : ")
		q_c_pop.append(float(spl[1]))

fig, ax = plt.subplots()

ax.plot(n_s, q_l_append)
ax.grid()
plt.show()


fig, ax = plt.subplots()

ax.plot(n_s, q_l_pop)
ax.grid()
plt.show()


fig, ax = plt.subplots()

ax.plot(n_s, q_d_append)
ax.grid()
plt.show()


fig, ax = plt.subplots()

ax.plot(n_s, q_d_pop)
ax.grid()
plt.show()


fig, ax = plt.subplots()

ax.plot(n_s, q_c_append)
ax.grid()
plt.show()


fig, ax = plt.subplots()

ax.plot(n_s, q_c_pop)
ax.grid()
plt.show()