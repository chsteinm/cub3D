
# TESTS TEXTURES

- changer les chemins pour tester si access est bien utilisé.
-> NO ./textures/north.xpm

- peux aussi modifier le nom du dossier et tester si ca foncionne toujours si nv chemin dans la map
-> NO ./texture_test/north.xpm

- changer les noms des textures
-> NO textures/nnorth.xpm OU textures/north.xpmm

- mettre deux fois les memes textures
-> NO textures/north.xpm
-> NO textures/north.xpmm

- mettre des espaces avant les textures
->        NO                    textures/north.xpm

- modifier le nom des directions
-> NOO textures/north.xpm 

- mettre dans rgb des valeurs > a 255
-> F 151,155,256

- mettre dans rgb des valeurs negatives
-> F 151,-155,156

- melanger l'ordre des couleurs/directions

# TEST MAPS

- mettre le personnage sur un mur
- mettre le personnage hors de la map
- mettre plusieurs/aucuns personnages
- mettre des caractres invalides
- mettre une ligne vide
- laisser la map ouverte
- faire un ilot en dehors de la map principale, y mettre le perso apres

# AUTRES TESTS

- enlever droits d'une map/dossier/texture
-> chmod 0 copy/west.xpm

- creer un dossier .cub et essayer de le mettre en tant que map

# TESTS DE BATARDS

- enlever l'env pour casser la mlx
-> env -i valgrind ./cub3D maps/ok_easy_cub.cub