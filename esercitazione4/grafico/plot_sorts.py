"""
❯ ./measure_sorts
Bubblesort:
2 - 1.7801e-05s
4 - 2.832e-06s
8 - 4.481e-06s
16 - 1.0121e-05s
32 - 2.0522e-05s
64 - 6.982e-05s
128 - 0.000275497s
256 - 0.00100844s
512 - 0.00447295s
1024 - 0.0161211s
2048 - 0.0546136s
4096 - 0.113982s
8192 - 0.312095s
Insertion Sort:
2 - 2.485e-06s
4 - 7.27e-07s
8 - 7.39e-07s
16 - 1.92e-06s
32 - 3.866e-06s
64 - 1.0502e-05s
128 - 3.0736e-05s
256 - 0.000130813s
512 - 0.00063834s
1024 - 0.00241596s
2048 - 0.00956122s
4096 - 0.0474303s
8192 - 0.15048s
Selection Sort:
2 - 3.026e-06s
4 - 7.86e-07s
8 - 1.071e-06s
16 - 2.202e-06s
32 - 5.464e-06s
64 - 1.6219e-05s
128 - 5.3949e-05s
256 - 0.000217884s
512 - 0.000974548s
1024 - 0.0031487s
2048 - 0.0138627s
4096 - 0.0668642s
8192 - 0.192127s
std::sort:
2 - 5.4473e-05s
4 - 1.133e-06s
8 - 1.402e-06s
16 - 2.452e-06s
32 - 5.862e-06s
64 - 1.5738e-05s
128 - 2.9473e-05s
256 - 4.7944e-05s
512 - 0.000112606s
1024 - 0.000289839s
2048 - 0.000571762s
4096 - 0.00107241s
8192 - 0.00247886s
❯
"""


import matplotlib.pyplot as plt

# dimensioni dei vettori
sizes = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192]

# tempi in secondi (output di ./measure_sorts)
bubble_times =    [1.7801e-05, 2.832e-06, 4.481e-06, 1.0121e-05, 2.0522e-05, 6.982e-05, 0.000275497, 0.00100844, 0.00447295, 0.0161211, 0.0546136, 0.113982, 0.312095]
insertion_times = [2.485e-06, 7.27e-07, 7.39e-07, 1.92e-06, 3.866e-06, 1.0502e-05, 3.0736e-05, 0.000130813, 0.00063834, 0.00241596, 0.00956122, 0.0474303, 0.15048]
selection_times = [3.026e-06, 7.86e-07, 1.071e-06, 2.202e-06, 5.464e-06, 1.6219e-05, 5.3949e-05, 0.000217884, 0.000974548, 0.0031487, 0.0138627, 0.0668642, 0.192127]
stdsort_times =   [5.4473e-05, 1.133e-06, 1.402e-06, 2.452e-06, 5.862e-06, 1.5738e-05, 2.9473e-05, 4.7944e-05, 0.000112606, 0.000289839, 0.000571762, 0.00107241, 0.00247886]

# creo il grafico
plt.plot(sizes, bubble_times,    label="Bubblesort")
plt.plot(sizes, insertion_times, label="Insertion Sort")
plt.plot(sizes, selection_times, label="Selection Sort")
plt.plot(sizes, stdsort_times,   label="std::sort")

plt.xlabel("dimensione vettore")
plt.ylabel("tempo (secondi)")
plt.title("tempi di sorting")
plt.legend()
plt.grid(True)
plt.show()