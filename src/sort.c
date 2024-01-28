#include "../include/sort.h"



void affiche_tab(int *tab, int taille) {
  for (int i = 0; i < taille; ++i) {
    printf(" %d |", tab[i]);
  }
  printf("\n");
}

int *creation_tableau(int taille) {
  int *tab = malloc(sizeof(int) * taille);
  return tab;
}

void initialisation_aleatoire(int *tab, int taille, int min, int max) {
  srand(time(NULL));
  for (int i = 0; i < taille; ++i) {
    tab[i] = min + rand() % (max - min + 1);
  }
}

void copie_tableau(int *source, int *destination, int taille) {
  for (int i = 0; i < taille; ++i) {
    destination[i] = source[i];
  }
}

int is_sorted(int *tab, int taille) {

  for (int i = 0; i < taille - 1; ++i) {
    if (tab[i] > tab[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubble_sort(int array[], int n) {
  int tmp;
  int swapped;

  for (int i = 0; i < n - 1; i++) {
    swapped = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (array[j] > array[j + 1]) {

        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
        swapped = 1;
      }
    }
    if (swapped == 0) {
      break;
    }
  }
}

void bubble_sort_opt(int *tab, int taille) {
  int i, j, swapped;

  for (i = 0; i < taille - 1; ++i) {
    swapped = 0;

    for (j = 0; j < taille - 1 - i; j++) { // Correction ici
      if (tab[j] > tab[j + 1]) {
        swap(&tab[j], &tab[j + 1]);
        swapped = 1;
      }
    }

    if (swapped == 0) {
      break;
    }
  }
}

void insertion_sort(int *tab, int taille) {
  int i, j, x;
  for (i = 1; i < taille; ++i) {
    x = tab[i];
    j = i;
    while (j > 0 && tab[j - 1] > x) {
      tab[j] = tab[j - 1];
      --j;
    }
    tab[j] = x;
  }
}

void counting_sort(int *tab, int taille) { // mise tout sur ça !
  int max = tab[0], i, x = 0;
  for (i = 1; i < taille; ++i) {
    if (tab[i] > max) {
      max = tab[i];
    }
  }

  int *comptage = calloc(max + 1, sizeof(int));
  
  for (i = 0; i < taille; ++i) {
    comptage[tab[i]]++;
  }
  
  for (i = 0; i <= max; ++i) {
    while (comptage[i] > 0) {
      tab[x++] = i;
      //x++;
      comptage[i]--;
    }
  }


  free(comptage);
}


void merge(int tab[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = tab[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = tab[m + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int tab[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(tab, l, m);
        mergeSort(tab, m + 1, r);

        merge(tab, l, m, r);
    }
}

void merge_sort(int *tab, int taille) {
    mergeSort(tab, 0, taille - 1);
}



void gnome_sort(int *tab, int taille) {
  u_int16_t pos = 0;
  while (pos < taille) {
    if (pos == 0 || tab[pos] >= tab[pos - 1]) {
      ++pos;
    } else {
      swap(&tab[pos], &tab[pos - 1]);
      --pos;
    }
  }
}

void odd_even_sort(int *tab, int taille) {
  bool sorted = false;
  u_int16_t i;
  while (!sorted) {
    sorted = true;
    for (i = 1; i < taille - 1; i += 2) {
      if (tab[i] > tab[i + 1]) {
        swap(&tab[i], &tab[i + 1]);
        sorted = false;
      }
    }
    for (i = 0; i < taille - 1; i += 2) {
      if (tab[i] > tab[i + 1]) {
        swap(&tab[i], &tab[i + 1]);
        sorted = false;
      }
    }
  }
}

void selection_sort(int *tab, int taille) {
  u_int16_t i, j;
  for (i = 0; i < taille - 1; ++i) {
    u_int16_t min = i;
    for (j = i + 1; j < taille; ++j) {
      if (tab[j] < tab[min]) {
        min = j;
      }
    }
    if (min != i) {
      swap(&tab[i], &tab[min]);
    }
  }
}

void comb_sort(int *tab, int taille){
    int interval = taille; 
    int i, temp;
    int swapped = 1; 

    while (interval > 1 || swapped) {
        interval = (int)(interval / 1.3);
        if (interval < 1) {
            interval = 1;
        }

        swapped = 0;

        for (i = 0; i < taille - interval; i++) {
            if (tab[i] > tab[i + interval]) {
                temp = tab[i];
                tab[i] = tab[i + interval];
                tab[i + interval] = temp;
                swapped = 1; 
            }
        }
    }



}

struct Node{
    int valeur;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->valeur = val;
    newNode->left = NULL;
    newNode->right=NULL;
    return newNode;
}

void insert(struct Node **root, int val){
    if(*root == NULL){
        *root = createNode(val);
    }else{
        if(val < (*root)->valeur){
            insert(&((*root)->left), val);
        } else{
            insert(&((*root)->right), val);
        }
    }
}

void inOrder(struct Node *root){
    if(root != NULL){
        inOrder(root->left);
        inOrder(root->right);
    }
}

void tree_sort(int *tab, int taille){
    struct Node *root = NULL;

    for(int i=0; i<taille; ++i){
        insert(&root, tab[i]);
    }

    inOrder(root);

}