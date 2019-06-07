#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include <fstream>
#include <iomanip>  

using namespace std;

int main(int argc, char const *argv[]) {
	srand(123456789);
	if (argc != 5) {
        printf("Informe 4 argumentos.\nEx.: 0 0.1 problem(mst or caminhos or fluxos) path_save.in");
        return 0;
    }

    int n = atoi(((string)argv[1]).c_str());
    double densidade = atof(((string)argv[2]).c_str());
    string problem = (string)argv[3];
    string trabalhos[3] = {"mst", "caminhos", "fluxos"};

    double A[n][n];
    random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(1.0, 200.0);

	int m = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if(((double) rand() / RAND_MAX) < densidade){
				A[i][j] = dis(gen);
				m++;
			}
		}
	}

	ofstream file;
    file.open(argv[4]);
    file << n << endl;
    file << m << endl;

    if(trabalhos[1].compare(argv[1]) == 0){
		file << 0 << endl;    	
    }

    if(trabalhos[2].compare(argv[1]) == 0){
    	file << 0 << endl; 
    	file << n-1 << endl; 
    }

    for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if(A[i][j] != 0){
				file << i << " " << j << " " << A[i][j] << setprecision(5) << endl; 
			}
		}
	}

    file.close();

    return 0;
}