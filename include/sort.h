#ifndef SORT_H  
#define SORT_H 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct Node;
/********************** Fonction benchmark **********************/  

void benchmark(char *nom, int taille, int min, int max);

int *lire_donnees(char *file_name, int *taille);  

/********************** Fonction d'affichage **********************/  

void affiche_tab(int * tab, int taille);

int is_sorted(int *tab,int taille); // retourne 1 si le tableau est trié, 0 sinon

int *creation_tableau(int taille); //alloue de la mémoire pour un tableau de la taille voulue et retourne un pointeur vers celui-ci

void initialisation_aleatoire(int *tab, int taille, int min, int max); //remplissage d'un tableau avec des valeurs aléatoires comprises entre min et max

void copie_tableau(int * source, int * destination, int taille); //copie du contenu du tableau source vers le tableau destination

/********************** Fonction de tri **********************/  

void swap(int * a, int * b);

void bubble_sort(int * tab, int taille);

void bubble_sort_opt(int *tab, int taille);

void insertion_sort(int *tab, int taille);

void counting_sort(int *tab, int taille);

void merge(int tab[], int l, int m, int r);

void mergeSort(int tab[], int l, int r);

void merge_sort(int *tab, int taille);

void gnome_sort(int *tab, int taille);

void odd_even_sort(int *tab, int taille);

void selection_sort(int *tab, int taille);

struct Node *createNode(int val);

void insert(struct Node **root, int val);

void inOrder(struct Node *root);

void tree_sort(int *tab, int taille);

void comb_sort(int *tab, int taille);

#endif 