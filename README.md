# Projet-QuadTree

**English Version**

Welcome to the QuadTree-based Point Cloud Subdivision project! The goal of this project is to implement the QuadTree algorithm to subdivide a given point cloud into isolated points or small groups based on their spatial distribution. This README will guide you through the project, explaining its purpose, implementation, and potential future prospects.

**Purpose**
The purpose of this project is to explore the application of QuadTree subdivision on point clouds. Unlike managing interactions, our focus is on efficiently organizing and isolating points using QuadTree. By dividing the point cloud space into quadrants, we can identify individual points or small groups and categorize them within QuadTree nodes.

**Implementation**


This project is organized into four modules:

1. QuadTree Module: This module handles all operations related to the QuadTree data structure, including QuadTree initialization, node addition, node subdivision, and particle processing. It includes the function traitement_particules() that performs the recursive QuadTree purge algorithm.

2. Particles Module: This module handles all operations related to particles, such as particle array initialization and particle addition.

3. Plist Module: This module handles all operations related to the list/cell, including adding a point to the head of a list, deleting a point, and allocating a cell array.

4. Graphics Module: This module is responsible for displaying the graphical representation using the MLV library. Please note that the Graphics module requires the MLV library to be installed and properly configured for the project.
Link : http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/globals_func.html

   

Please note that these modules work together to achieve the desired functionality of the project.

**Description**

The project will open with a menu where the user can choose from the following options: window size, minimum number of particles in a node (Kp), minimum node resolution size (Wmin), total number of particles (Np), and random/click mode.

If the user doesn't provide any options, they can simply click on the menu (twice), and they will be able to play with the default mode (Np: 20, Kp: 3, Wmin: 1, window size: 512).

The menu provides a convenient way for users to customize the settings according to their preferences. By specifying the options, users can define the size of the graphical window, adjust the parameters for node subdivision (Kp and Wmin), set the total number of particles in the system (Np), and choose between random or click mode.

However, if the user decides not to provide any options, they can start the program by clicking on the menu twice. This will initiate the default mode, where the system will use the following settings: Np = 20, Kp = 3, Wmin = 1, and window size = 512. This allows users to quickly start interacting with the program without having to specify the settings explicitly.


Thank you for your attention !

---------------------------------------------------------------------------------------------------------------------------------------------------------

**French Version**


Bienvenue dans le projet de subdivision de nuages de points basé sur QuadTree ! L'objectif de ce projet est d'implémenter l'algorithme QuadTree pour subdiviser un nuage de points donné en points isolés ou petits groupes en fonction de leur répartition spatiale. Ce fichier README vous guidera à travers le projet, expliquant son objectif, son implémentation et ses perspectives d'avenir potentielles.

**Objectif**

Le but de ce projet est d'explorer l'application de la subdivision QuadTree sur les nuages de points. Contrairement à la gestion des interactions, notre attention se porte sur l'organisation et l'isolation efficaces des points en utilisant le QuadTree. En divisant l'espace du nuage de points en quadrants, nous pouvons identifier des points individuels ou de petits groupes et les catégoriser dans les nœuds du QuadTree.

**Implémentation**

Ce projet est organisé en quatre modules :

Module QuadTree : Ce module gère toutes les opérations liées à la structure de données QuadTree, y compris l'initialisation du QuadTree, l'ajout de nœuds, la subdivision des nœuds et le traitement des particules. Il comprend la fonction traitement_particules() qui effectue l'algorithme récursif de purge QuadTree.

Module Particules : Ce module gère toutes les opérations liées aux particules, telles que l'initialisation du tableau de particules et l'ajout de particules.

Module Pliste : Ce module gère toutes les opérations relatives aux listes/cellules, y compris l'ajout d'un point en tête de liste, la suppression d'un point et l'allocation d'un tableau de cellules.

Module Graphique : Ce module est responsable de l'affichage graphique à l'aide de la bibliothèque MLV. Veuillez noter que le module Graphique nécessite l'installation et la configuration correcte de la bibliothèque MLV pour le projet.
Lien : http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/globals_func.html

Veuillez noter que ces modules travaillent ensemble pour atteindre la fonctionnalité souhaitée du projet.

**Description**

Le projet s'ouvrira sur un menu où l'utilisateur pourra choisir parmi les options suivantes : taille de la fenêtre, nombre minimal de particules dans un nœud (Kp), taille de résolution minimale d'un nœud (Wmin), nombre total de particules (Np) et mode aléatoire/clic.

Si l'utilisateur ne renseigne aucune option, il lui suffira de cliquer deux fois sur le menu et il pourra utiliser le mode par défaut (Np : 20, Kp : 3, Wmin : 1, taille de la fenêtre : 512).

Le menu offre une manière pratique aux utilisateurs de personnaliser les paramètres selon leurs préférences. En spécifiant les options, les utilisateurs peuvent définir la taille de la fenêtre graphique, ajuster les paramètres de subdivision des nœuds (Kp et Wmin), définir le nombre total de particules dans le système (Np) et choisir entre le mode aléatoire ou le mode clic.

Cependant, si l'utilisateur décide de ne pas spécifier d'options, il peut


Merci de votre attention !


