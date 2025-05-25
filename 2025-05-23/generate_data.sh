parallel 'g++ -O{} basic_optimization.cpp -o basic_optimization{}.x' ::: 0 1 2 3 fast

parallel './basic_optimization{1}.x 1024 {2} 10 >> data-{1}.txt' ::: 0 1 2 3 fast ::: {5..100..5}

for level in 0 1 2 3 fast; do
    if [[ -f "data-${level}.txt" ]]; then
        sort -nk 2 data-${level}.txt > datasorted_${level}.txt;
        rm data-${level}.txt
    else
        echo "Error: data-${level}.txt no existe."
    fi
done
