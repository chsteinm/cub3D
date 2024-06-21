#!/bin/bash

MAPS_FOLDER="./maps"

RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"

print_separator() {
	echo -e "\n${BLUE}******************************************************${RESET}\n"
}

# Compter le nombre total de cartes
total_maps=$(ls -1 $MAPS_FOLDER/*.cub | wc -l)
current_map=0

# Boucle sur chaque fichier .cub dans le dossier des cartes
for map_file in $MAPS_FOLDER/*.cub; do
	# Mise à jour du compteur de cartes
	((current_map++))

	print_separator
	echo -e "Testing map ${BLUE}$current_map/$total_maps${RESET}: $map_file"

	# Exécution du programme et capture de la sortie
	output=$(./cub3D "$map_file" 2>&1)

	# Vérifier si la sortie contient "Error"
	if echo "$output" | grep -q "Error"; then
		echo -e "${RED}Message error detected ! 😱 ${RESET}"
		echo -e "${YELLOW}Error message from program:${RESET}"
		echo -e "----------"
		echo -e "$output"
		echo -e "----------\n"
	else
		echo -e "${GREEN}The map is valid ! 😎${RESET}"
	fi

	echo -e "${CYAN}Finished testing $map_file${RESET}"
done

print_separator
echo -e "\n${GREEN}********** Well done, all $total_maps maps tested 🗒️🖊️  *********\n${RESET}"
