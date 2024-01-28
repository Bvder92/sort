import ctypes
import numpy as np
import matplotlib.pyplot as plt 
import time 
import argparse
import random
import sys 

# Chargement de la bibliothèque partagée
sort_lib = ctypes.CDLL('./libsort.so')

parser = argparse.ArgumentParser(description='Analyse des algorithmes de tri.')
parser.add_argument('algorithm', type=str, help='Nom de l\'algorithme de tri')
args = parser.parse_args()


bubble_sort = sort_lib.bubble_sort  
bubble_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
bubble_sort.restype = None  

bubble_sort_opt = sort_lib.bubble_sort_opt
bubble_sort_opt.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
bubble_sort_opt.restype = None

insertion_sort = sort_lib.insertion_sort
insertion_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
insertion_sort.restype = None 

counting_sort = sort_lib.counting_sort
counting_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
counting_sort.restype = None

merge_sort = sort_lib.merge_sort
merge_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
merge_sort.restype = None

selection_sort = sort_lib.selection_sort
selection_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
selection_sort.restype = None


gnome_sort = sort_lib.gnome_sort
gnome_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
gnome_sort.restype = None

odd_even_sort = sort_lib.odd_even_sort
odd_even_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
odd_even_sort.restype = None

tree_sort = sort_lib.tree_sort
tree_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
tree_sort.restype = None

comb_sort = sort_lib.comb_sort
comb_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]  
comb_sort.restype = None 


def measure_execution_time(sort_func, data):
    
    data_np = np.array(data, dtype=np.int64)

    start_time = time.time()
    sort_func(data_np.ctypes.data_as(ctypes.POINTER(ctypes.c_int)), len(data))
    end_time = time.time()

    return end_time - start_time  


def generate_primes(upper_bound, n):
    primes = []
    while len(primes) < n:
        num = random.randint(2, upper_bound)
        if num > 1 and all(num % i != 0 for i in range(2, int(num ** 0.5) + 1)):
            primes.append(num)
    return primes

'''
data_sets = {
    "Random 0 to 20": np.random.randint(0, 21, size=size).tolist(),
    "Random 0 to INT_MAX": np.random.randint(0, 2**31 - 1, size=size).tolist(),
    "Ascending": list(range(size)),
    "Descending": list(range(size, -1, -1)),
    "Constant": [5] * size,
    "Random Even": np.random.randint(0, 10000, size=size) * 2,
    "Random Odd": np.random.randint(0, 10000, size=size) * 2 + 1,
    "Powers of 2": [2**i for i in range(size)],
    "Prime Numbers": generate_primes(size)
}
'''

sizes_to_test = [100, 500, 1000, 5000, 10000, 20000]  # Tailles à tester

data_sets = {
    "Random 0 to 20": [np.random.randint(0, 21, size=size).tolist() for size in sizes_to_test],
    "Random 0 to INT_MAX": [np.random.randint(0, 2**31 - 1, size=size).tolist() for size in sizes_to_test],
    "Ascending": [list(range(size)) for size in sizes_to_test],
    "Descending": [list(range(size - 1, -1, -1)) for size in sizes_to_test],
    "Constant": [[5] * size for size in sizes_to_test],
    "Random Even": [np.random.randint(0, 1000, size=size) * 2 for size in sizes_to_test],
    "Random Odd": [np.random.randint(0, 1000, size=size) * 2 + 1 for size in sizes_to_test],
    "Powers of 2": [[2** np.random.randint(0, 25)] * size for size in sizes_to_test],
    "Prime Numbers": [generate_primes(500, size) for size in sizes_to_test]
}


for data_name, data in data_sets.items():
    execution_times = []

    for subset_data in data:
        if args.algorithm == 'bubble_sort':
            execution_time = measure_execution_time(bubble_sort, subset_data)
        elif args.algorithm == 'bubble_sort_opt':
            execution_time = measure_execution_time(bubble_sort_opt, subset_data)
        elif args.algorithm == 'insertion_sort':
            execution_time = measure_execution_time(insertion_sort, subset_data)        
        elif args.algorithm == 'counting_sort':
            execution_time = measure_execution_time(counting_sort, subset_data)
        elif args.algorithm == 'merge_sort':
            execution_time = measure_execution_time(merge_sort, subset_data)           
        elif args.algorithm == 'selection_sort':
            execution_time = measure_execution_time(selection_sort, subset_data)
        elif args.algorithm == 'gnome_sort':
            execution_time = measure_execution_time(gnome_sort, subset_data)
        elif args.algorithm == 'odd_even_sort':
            execution_time = measure_execution_time(odd_even_sort, subset_data)
        elif args.algorithm == 'tree_sort':
            execution_time = measure_execution_time(tree_sort, subset_data)
        elif args.algorithm == 'comb_sort':
            execution_time = measure_execution_time(comb_sort, subset_data)
        else :
            print("L algorithme entré n'est pas connu ! ")
            sys.exit(1) 

        
        
        
        execution_times.append(execution_time)

    # Tracer le graphique pour chaque ensemble de données avec différentes tailles
    plt.plot(sizes_to_test, execution_times, marker='o', label=data_name)

# Configurer le graphique
plt.xlabel('Taille des données')
plt.ylabel('Temps d\'exécution')
plt.title('Temps d\'exécution en fonction de la taille des données')
plt.legend()
plt.grid(True)
plt.show()