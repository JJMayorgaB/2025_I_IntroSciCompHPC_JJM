#Se realiza la compilación 
g++ matrixtime.cpp -o matrixtime.x

#Se ejecuta el programa y se guardan los datos
parallel './matrixtime.x {1} >> data.txt'  {5..5000..50}

#En caso de que la salida de los datos no se de ordenadamente, ordenamos los datos
if [[ -f "data.txt" ]]; then
    sort -nk 1 data.txt > datasorted.txt;
    rm data.txt
else
    echo "Error: data.txt no existe."
fi

#Eliminamos todos los ejecutables para mantener un entorno limpio
rm *.x