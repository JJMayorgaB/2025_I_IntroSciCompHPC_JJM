#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <cctype>  
#include <vector>


void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    const std::string FNAME = argv[1];

    analyze_document(FNAME);

    return 0;
}

void analyze_document(const std::string & fname)
{

    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (file >> word) {
        
        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        
       
        while (!word.empty() && std::ispunct(static_cast<unsigned char>(word.back()))) 
        {
            word.pop_back();
        }
        
        if (!word.empty() && word.length() >3) 
        {
            word_count[word]++;
        }
    }

    std::vector<std::pair<std::string, int>> sorted_words(word_count.begin(), word_count.end());
    
    std::sort(
        sorted_words.begin(),
        sorted_words.end(),
        [](const auto &a, const auto &b) {
            return a.second > b.second; // Orden descendente
        }
    );

    //Seleccionar las top 20
    std::vector<std::pair<std::string, int>> top20;

    int limit = std::min(20, static_cast<int>(sorted_words.size()));
    for (int i = 0; i < limit; ++i) {
        top20.push_back(sorted_words[i]);
    }

    //Imprimir resultados
    std::cout << "Top 20 palabras más frecuentes:\n";
    for (const auto &entry : top20) {
        std::cout << entry.first << "\t" << entry.second << "\n";
    }
}