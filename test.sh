#!/bin/bash

# Colores para la salida
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # Sin color

# Función para ejecutar el programa y verificar fugas de memoria
check_file() {
    local file="$1"
    local expected_output="$2"
    
    # Ejecuta el programa y captura su salida
    output=$(./cub3d "$file")
    
    # Ejecuta Valgrind para comprobar si hay fugas de memoria
    leaks=$(valgrind --leak-check=full --error-exitcode=1 ./mi_programa "$file" 2>&1 | grep "definitely lost")

    if [ "$expected_output" = "no_output" ]; then
        if [ -z "$output" ] && [ -z "$leaks" ]; then
            echo -e "${GREEN}El archivo $file está bien.${NC}"
        elif [ -z "$output" ] && [ -n "$leaks" ]; then
            echo -e "${YELLOW}El archivo $file generó fugas de memoria.${NC}"
        else
            echo -e "${RED}El archivo $file falló la prueba.${NC}"
        fi
    elif [ "$expected_output" = "output_expected" ]; then
        if [ -n "$output" ] && [ -z "$leaks" ]; then
            echo -e "${GREEN}El archivo $file está bien.${NC}"
        elif [ -z "$output" ] && [ -n "$leaks" ]; then
            echo -e "${YELLOW}El archivo $file generó fugas de memoria.${NC}"
        else
            echo -e "${RED}El archivo $file falló la prueba.${NC}"
        fi
    fi
}

# Verificar archivos en el directorio ./maps/good/
echo "Verificando archivos en ./maps/good/..."
find ./maps/good/ -type f -name "*.cub" | while read -r file; do
    # En good, los archivos que no devuelven salida están bien (verde)
    check_file "$file" "no_output"
done

# Verificar archivos en el directorio ./maps/bad/
echo "Verificando archivos en ./maps/bad/..."
find ./maps/bad/ -type f -name "*.cub" | while read -r file; do
    # En bad, los archivos que devuelven salida están bien (verde)
    check_file "$file" "output_expected"
done
