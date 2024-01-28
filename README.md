# Projet de Tri en C avec Python

## Description

Ce projet met en œuvre plusieurs algorithmes de tri implémentés en C, avec une interface Python pour mesurer et comparer leurs temps d'exécution. Les algorithmes de tri inclus sont : 
- bubble sort
- insertion sort
- counting sort
- merge sort
- selection sort
- gnome sort
- odd-even sort
- tree sort
- comb sort

Les détails de ces algorithmes sont visibles sur : https://fr.wikipedia.org/wiki/Algorithme_de_tri

## Installation

1. Clonez le dépôt GitHub :

```bash
git clone https://github.com/bvder92/sort.git
cd sort
```
2. Compilez le projet pour utiliser la bibliothèque partagée :

```
make
```
.3 Assurez-vous d'avoir les dépendances nécessaires : 

Numpy :
```
pip install Numpy
```
Matplotlib : 
```
pip install matplotlib
```

## Utilisation

Afin d'observer les performances d'un algorithme de tri il vous suffit d'entrer la commande qui suit : 

```
python3 main.py --example_sort
```

A noter que selon l'algorithme que vous souhaitez tester, il faudra impérativement mettre le nom de l'algorithme suivi de ```_sort```

