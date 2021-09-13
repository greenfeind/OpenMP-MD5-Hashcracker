
#include <cstring>
#include <ctime>
#include <iostream>
#include <numeric> 
#include <omp.h>
#include <sstream>
#include <string>

#include "md5.h"

using namespace std;

int test_hash(std::string hString, std::string tString){

	MD5 md5;
	char *tstr = new char[tString.length() + 1];
	strcpy(tstr, tString.c_str());
	if ( hString == md5.digestString(tstr) ){
		std::cout << "Match found: " << tString << std::endl; 
		return 10;}
		else { return 1; }
}

int main(int argc, char *argv[]){
	
	char cars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int carlen = 63;
	MD5 md5;
	std::string utString;
	std::string uHash;
	std::string tHash;
	std::string tPass;
	std::string sstr;
	std::clock_t start;
	int test_res = 2;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
		
	
	std::cout << "This program makes use of the md5.h file available from: \n";
	std::cout << "github.com/Ex094/HashcrackerV.2/blob/master/md5.h\n\n";
	std::cout << "The shorter the inital string, the longer its going to take" << endl;
	std::cout << "Regex for expected string: [0-9,A-Z,a-z,\" \"]{1,7}" << std::endl;
	std::cout << "Enter a MD5 hash to be cracked: " << std::endl; 
	std::cin >> uHash;
	
	start = std::clock();
	
	#pragma omp parallel
		
	#pragma omp parallel for private(i, j, k, l, m, n, o, sstr, tPass)
	for( i = omp_get_thread_num() ; i < carlen; i += omp_get_num_threads() ){
		for( j = 0 ; j < carlen; j++){
			for( k = 0 ; k < carlen; k++){
				for( l = 0 ; l < carlen; l++){
					for( m = 0 ; m < carlen; m++){
						for( n = 0 ; n < carlen; n++){
							for( o = 0 ; o < carlen; o++){
								std::stringstream sstr;
								sstr << cars[i] << cars[j] << cars[k] << cars[l]; 
								sstr << cars[m] << cars[n] << cars[o];
								std::string tPass = sstr.str();
								if ( test_hash(uHash, tPass) == 10 ){ 
									std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
									i = 63 ; j =63 ; k = 63 ; l = 63 ; 
									m = 63 ; n = 63 ; o = 63 ; }								
							}
							std::stringstream sstr;
							sstr << cars[i] << cars[j] << cars[k] << cars[l]; 
							sstr << cars[m] << cars[n];
							std::string tPass = sstr.str();
							if ( test_hash(uHash, tPass) == 10 ){ 
								std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
								i = 63 ; j =63 ; k = 63 ; l =63 ; m = 63 ; n = 63 ; }
						}
						std::stringstream sstr;
						sstr << cars[i] << cars[j] << cars[k] << cars[l]; 
						sstr << cars[m];
						std::string tPass = sstr.str();
						if ( test_hash(uHash, tPass) == 10 ){ std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
							i = 63 ; j =63 ; k = 63 ; l =63 ; m = 63 ; }
					}
					std::stringstream sstr;
					sstr << cars[i] << cars[j] << cars[k] << cars[l]; 
					std::string tPass = sstr.str();
					if ( test_hash(uHash, tPass) == 10 ){ 
						std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
						i = 63 ; j =63 ; k = 63 ; l =63 ; }
				}
				std::stringstream sstr;
				sstr << cars[i] << cars[j] << cars[k]; 
				std::string tPass = sstr.str();
				if ( test_hash(uHash, tPass) == 10 ){ 
					std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
					i = 63 ; j =63 ; k = 63 ; }
			}
			std::stringstream sstr;
			sstr << cars[i] << cars[j]; 
			std::string tPass = sstr.str();
			if ( test_hash(uHash, tPass) == 10 ){ 
				std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
				i = 63 ; j =63 ; }
			}
		std::stringstream sstr;
		sstr << cars[i]; 
		std::string tPass = sstr.str();
		if ( test_hash(uHash, tPass) == 10 ){ 
			std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
			i = 63 ; }
	}
	#pragma omp critical
	std::cout << "Time: " << (std::clock() - start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << std::endl;
	
	return 0; 
			}
