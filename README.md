[🇫🇷 French](#french)

<a id="english"></a>
# 🇬🇧 Push_Swap

*This project has been created as part of the 42 curriculum by* _`rcompain`_.

## Sommary

 - [Description](#description)
 - [Instructions](#instructions)
   - [Compilation](#compilation)
   - [Execution](#execution)
 - [Allowed Operations](#allowed-operations)
 - [Algorithm Overview](#algorithm-overview)
   - [Index Mapping](#index-mapping)
   - [Small Stack Optimization](#small-stack-optimization)
   - [Chunk-Based Push to Stack B (Butterfly Algorithm)](#chunk-based-push-to-stack-b-butterfly-algorithm)
   - [Cost Calculation and Reinsertion into Stack A](#cost-calculation-and-reinsertion-into-stack-a)
   - [Instruction Storage and Optimization](#instruction-storage-and-optimization)
   - [Final Rotation and Output](#final-rotation-and-output)
 - [Error Handling](#error-handling)
 - [Resources](#resources)

---

## Description

**Push_swap** is an algorithmic project whose goal is to sort a stack of 
integers using a limited set of instructions and the smallest possible 
number of operations.

The program receives a list of integers as arguments, places them into a 
stack called **stack A**, and sorts them in ascending order using an 
auxiliary stack (**stack B**). Only a specific set of stack operations is 
allowed, making this project a challenge in algorithm design, optimization, 
and data structure manipulation.

The main objective is not only to sort the numbers correctly, but also 
to do so efficiently, by minimizing the total number of operations.

---

## Instructions

### Compilation

To compile this project, run:

```bash
make
```

This will generate an executable named:

```text
push_swap
```

To clean objects files:

```bash
make clean
```

To remove the executable and objects files:

```bash
make fclean
```

To remove all and recompile:

```bash
make re
```
---

### Execution

Run the program with a list of integers arguments:

```bash
./push_swap 3 2 1
```
The program will output a sequence of instructions that sorts the stack.

## Allowed operations

The program uses the following operations:

 * `sa` -> swap the first two elements of stack a.
 * `pa`, `pb` -> push elements between stacks.
 * `ra`, `rb`, `rr` -> rotate stack a or b or same time.
 * `rra`, `rrb`, `rrr` reverse rotate stack a or b or same time.

---

## Algorithm Overview

The algorithm is structured into multiple stages to ensure both correctness and
operation efficiency.

### Index Mapping

All values from **stack A** are first converted into a normalized index range.
This mapped version of the stack, referred to as **map**, allows the algorithm to
operate on relative ordering rather than raw integer values, simplifying comparisons
and decision-making.

### Small Stack Optimization

If the size of **stack A** is less than or equal to 5, a dedicated **tiny_sort**
algorithm is used.
This specialized sorting logic guarantees an optimal number of operations for small
inputs.

### Chunk-Based Push to Stack B (Butterfly Algorithm)

For larger inputs, all elements from **stack A** are pushed to **stack B** using a
chunk-based strategy, commonly known as the **butterfly algorithm**.

- The mapped values are divided into chunks
- Elements belonging to the current chunk are pushed from **stack A** to **stack B**
- The lower half of each chunk is pushed using `pb`
- The upper half is pushed using `pb` followed by `rb`

This technique spreads values evenly inside **stack B**, preparing it for efficient
reinsertion into **stack A**.

### Cost Calculation and Reinsertion into Stack A

To move values back from **stack B** to **stack A**, the algorithm computes the cost
of reinsertion for each element in **stack B**.

For every value, all possible rotation scenarios are evaluated:

 - `ra` + `rb`
 - `rra` + `rrb`
 - `ra` + `rrb`
 - `rra` + `rb`

The element with the lowest total cost is selected and pushed back into **stack A**.
This process is repeated until **stack B** is empty.

### Instruction Storage and Optimization

All generated operations are stored in a linked list during execution.
Once the sorting logic is complete, this list is optimized by:

- Merging compatible rotations into `rr`
- Merging reverse rotations into `rrr`
- Removing redundant instruction pairs such as `pb` followed immediately by `pa`

This optimization phase reduces the total number of operations without altering the
sorting result.

### Final Rotation and Output

After all elements have been reinserted, **stack A** is rotated to place the smallest
value at the top.

Finally, the optimized list of instructions is written to standard output (`stdout`),
representing the final solution.

---

## Error Handling

The program handles the following errors :

 * Non-numeric arguments.
 * Duplicates numbers.
 * Integer overflow/underflow.
 * Invalid input format.

In caseof an error, the program outputs:

```text
Error
```

---

## Resources

 * 42 Subject PDF: *Push_swap*.
 * Excalidraw for brainstorming and structuring ideas.
 * Understanding the different types of algorithms. [Algomius](https://www.youtube.com/@algomius) on Youtube.
 * The 42 following students for the time spent discussing ideas, algorithms,
and optimization strategies:
     - `pchazalm` 
     - `bamagere`
     - `tseche`
 * AI was used to further research and deepen understanding of new concepts.


[🇬🇧  TOP](#english)


<a id="french"></a>
# 🇫🇷 Push_Swap

*Ce projet a été créé dans le cadre du cursus 42 par *`rcompain`*.

## Sommaire

 - [Description](#descriptionfr)
 - [Instructions](#instructionfr)
   - [Compilation](#compilationfr)
   - [Exécution](#executionfr)
 - [Opérations autorisées](#operationsfr)
 - [Aperçu de l'algorithme](#algofr)
   - [Indexation](#indexationfr)
   - [Optimisation pour petites piles](#optifr)
   - [Push par chunks vers la pile B (Algorithme Papillon)](#papillonfr)
   - [Calcul du coût et réinsertion dans la pile A](#calculfr)
   - [Stockage et optimisation des instructions](#stockagefr)
   - [Rotation finale et sortie](#rotationfr)
 - [Gestion des erreurs](#erreurfr)
 - [Ressources](#ressourcesfr)

---
<a id="descriptionfr"></a>
## Description.

**Push_swap** est un projet algorithmique dont l'objectif est de trier une pile d'entiers 
en utilisant un nombre limité d'instructions et le moins d'opérations possible.

Le programme reçoit une liste d'entiers en arguments, les place dans une 
pile appelée **pile A**, et les trie par ordre croissant en utilisant une 
pile auxiliaire (**pile B**). Seul un ensemble spécifique d'opérations sur les piles est 
autorisé, ce qui rend ce projet un défi en conception d'algorithmes, optimisation et 
manipulation de structures de données.

L'objectif principal est non seulement de trier correctement les nombres, mais aussi 
de le faire efficacement, en minimisant le nombre total d'opérations.

---

<a id="instructionfr"></a>
## Instructions

<a id="compilationfr"></a>
### Compilation

Pour compiler ce projet, exécutez :

```bash
make
```

Cela générera un exécutable nommé :

```text
push_swap
```

Pour supprimer les fichiers objets :

```bash
make clean
```

Pour supprimer l’exécutable et les fichiers objets :

```bash
make fclean
```

Pour tout supprimer et recompiler :

```bash
make re
```

---

<a id="executionfr"></a>
### Exécution

Lancez le programme avec une liste d’entiers en arguments :

```bash
./push_swap 3 2 1
```
Le programme affichera une suite d’instructions permettant de trier la pile.

<a id="operationfr"></a>
## Opérations autorisées

Le programme utilise les opérations suivantes :

* `sa` → échange les deux premiers éléments de la pile a.
* `pa`, `pb` → push un élément d’une pile vers l’autre.
* `ra`, `rb`, `rr` → fait une rotation de la pile a, de la pile b ou des deux en même temps.
* `rra`, `rrb`, `rrr` → fait une rotation inverse de la pile a, de la pile b ou des deux en même temps.

<a id="algofr"></a>
## Présentation de l’algorithme

L’algorithme est structuré en plusieurs étapes afin d’assurer à la fois la 
justesse du tri et l’efficacité en nombre d’opérations.

<a id="indexationfr"></a>
### Indexation des valeurs

Toutes les valeurs de **stack A** sont d’abord converties dans une plage
d’indices normalisée. Cette version indexée de la pile, appelée **map**,
permet à l’algorithme de travailler sur des ordres relatifs plutôt que sur
les valeurs entières brutes, ce qui simplifie les comparaisons et la prise
de décision.

<a id="optifr"></a>
### Optimisation pour les petites piles

Si la taille de **stack A** est inférieure ou égale à 5, un algorithme dédié
appelé **tiny_sort** est utilisé.
Cette logique de tri spécialisée garantit un nombre optimal d’opérations
pour les petites entrées.

<a id="papillonfr"></a>
### Envoi par blocs vers la pile B (algorithme du papillon)

Pour des entrées plus importantes, tous les éléments de stack A sont
envoyés vers stack B à l’aide d’une stratégie par blocs, communément
appelée l’algorithme du butterfly.

 * Les valeurs indexées sont divisées en blocs.
 * Les éléments appartenant au bloc courant sont poussés de stack A vers stack B.
 * La moitié basse du bloc est poussée avec `pb`.
 * La moitié haute est poussée avec `pb` suivie de `rb`.

Cette technique permet de répartir les valeurs de manière équilibrée dans
stack B, en préparant une réinsertion efficace dans **stack A**.

<a id="calculfr"></a>
### Calcul des coûts et réinsertion dans la pile A

Pour rapatrier les valeurs de stack B vers stack A, l’algorithme
calcule le coût de réinsertion pour chaque élément présent dans stack B.

Pour chaque valeur, tous les scénarios possibles de rotations sont évalués :

 * `ra` + `rb`
 * `rra` + `rrb`
 * `ra` + `rrb`
 * `rra` + `rb`

L’élément ayant le coût total le plus faible est sélectionné et poussé dans
**stack A**. Ce processus est répété jusqu’à ce que **stack B** soit vide.

<a id="stockagefr"></a>
### Stockage et optimisation des instructions

Toutes les opérations générées sont stockées dans une liste chaînée pendant
l’exécution.
Une fois la logique de tri terminée, cette liste est optimisée en :

 * Fusionnant les rotations compatibles en `rr`.
 * Fusionnant les rotations inverses en `rrr`.
 * Supprimant les paires d’instructions redondantes, comme `pb` suivi
immédiatement de `pa`.

Cette phase d’optimisation réduit le nombre total d’opérations sans modifier
le résultat du tri.

<a id="rotationfr"></a>
### Rotation finale et affichage

Après la réinsertion de tous les éléments, **stack A** est tournée afin de
placer la plus petite valeur en haut de la pile.

Enfin, la liste optimisée d’instructions est écrite sur la sortie standard,
représentant la solution finale.

---

<a id="erreurfr"></a>
## Gestion des erreurs

Le programme gère les erreurs suivantes :

 * Arguments non numériques.
 * Nombres en double.
 * Dépassement ou sous-dépassement d’entier.
 * Format d’entrée invalide.

En cas d’erreur, le programme affiche :

```text
Error
```

---

<a id="ressourcesfr"></a>
## Ressources

 * Sujet PDF 42 : *Push_swap*
 * Excalidraw pour le brainstorming et la structuration des idées.
 * Compréhension des différents types d’algorithmes : chaîne YouTube
Algomius.
 * Les étudiants de 42 suivants pour le temps passé à discuter des idées,
des algorithmes et des stratégies d’optimisation :
    * `pchazalm`
    * `bamagere`
    * `tseche`
 * L’IA a été utilisée pour approfondir les recherches et améliorer la
compréhension de nouveaux concepts.

[🇫🇷  TOP](#french)  [🇬🇧  TOP](#english)
