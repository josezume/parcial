#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <numeric>

int main(){
    try{
        std::ifstream infile("numeros.txt");
        if(!infile)
            throw std::runtime_error("No se pudo abrir el archivo numeros.txt");
        std::vector<int> nums;
        int x;
        while(infile >> x){
            nums.push_back(x);
        }
        if(infile.bad())
            throw std::runtime_error("Error de lectura en numeros.txt");
        infile.close();
        if(nums.empty())
            throw std::runtime_error("El archivo numeros.txt no contiene numeros");
        long long suma = std::accumulate(nums.begin(), nums.end(), 0LL);
        size_t cantidad = nums.size();
        double promedio = static_cast<double>(suma) / cantidad;
        std::ofstream outfile("resultados.txt");
        if(!outfile)
            throw std::runtime_error("No se pudo abrir el archivo resultados.txt");
        outfile << "Suma: " << suma << "\n";
        outfile << "Cantidad: " << cantidad << "\n";
        outfile << "Promedio: " << promedio << "\n";
        outfile.close();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
