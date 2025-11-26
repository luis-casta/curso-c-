#!/bin/bash

# Script para compilar todos los archivos .cpp que no tienen ejecutable
# Autor: Generado automáticamente
# Uso: ./compilar_pendientes.sh

# Colores para output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  Compilador Automático de C++${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Contador de archivos
total_cpp=0
compilados=0
ya_compilados=0
errores=0

# Directorio base (donde está el script)
DIR_BASE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo -e "${YELLOW}Buscando archivos .cpp en: ${DIR_BASE}${NC}\n"

# Buscar todos los archivos .cpp recursivamente
while IFS= read -r -d '' archivo_cpp; do
    ((total_cpp++))
    
    # Obtener el directorio y nombre base del archivo
    dir_archivo=$(dirname "$archivo_cpp")
    nombre_base=$(basename "$archivo_cpp" .cpp)
    ejecutable="${dir_archivo}/${nombre_base}"
    
    # Verificar si el ejecutable existe y si está actualizado
    if [ -f "$ejecutable" ] && [ "$ejecutable" -nt "$archivo_cpp" ]; then
        echo -e "${GREEN}✓${NC} Ya compilado: ${archivo_cpp#$DIR_BASE/}"
        ((ya_compilados++))
    else
        # Compilar el archivo
        echo -e "${YELLOW}⚙${NC}  Compilando: ${archivo_cpp#$DIR_BASE/}"
        
        if g++ -std=c++17 -Wall "$archivo_cpp" -o "$ejecutable" 2>&1; then
            echo -e "${GREEN}✓${NC} Compilado exitosamente: ${ejecutable#$DIR_BASE/}\n"
            ((compilados++))
        else
            echo -e "${RED}✗${NC} Error al compilar: ${archivo_cpp#$DIR_BASE/}\n"
            ((errores++))
        fi
    fi
done < <(find "$DIR_BASE" -type f -name "*.cpp" -print0)

# Resumen final
echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}  Resumen de Compilación${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total de archivos .cpp encontrados: ${total_cpp}"
echo -e "${GREEN}Compilados exitosamente: ${compilados}${NC}"
echo -e "${YELLOW}Ya estaban compilados: ${ya_compilados}${NC}"
if [ $errores -gt 0 ]; then
    echo -e "${RED}Errores de compilación: ${errores}${NC}"
fi
echo -e "${BLUE}========================================${NC}\n"

# Código de salida
if [ $errores -gt 0 ]; then
    exit 1
else
    exit 0
fi
