/* 	UNIVERSIDADE DO ESTADO DO AMAZONAS - UEA
	LETÍCIA DA SILVA MOTA

	ALGORITMO PARA GERAÇÃO DE MATRIZ DITHER NxN A PARTIR DA MATRIZ DITHER 2x2

	0 2
	3 1
	
	OBS: N DEVE SER MULTIPLO DE 2
*/

#include <iostream>

using namespace std;

int** dither(int n);

int main(){
	
	int n;
	
	cout << "determine a dimensao da matriz dither:" << endl;
	cin >> n;
	
	int** mdither = new int*[n];
	for(int i=0; i<n; i++){
		mdither[i] = new int[n];
	}
	
	/*	MATRIZ DITHER RESULTANTE	*/
	mdither = dither(n);
	
	/*	PRINT DA MATRIZ DITHER	*/
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << mdither[i][j] << '\t';
		}
		cout << endl;
	}	
		
	return 0;
}

/*	FUNÇÃO DITHER	*/
int** dither(int n){
	
	/*	DN - MATRIZ DITHER DIMENSAO N	*/
	int** dn = new int*[n];
	for(int i=0; i<n; i++){
		dn[i] = new int[n];
	}
	
	/*	DU - MATRIZ UNITARIA	*/
	int** du = new int*[n];
	for(int i=0; i<n; i++){
		du[i] = new int[n];
	}
	
	/*	INICIALIZAÇÃO DA MATRIZ UNITARIA - DU	*/

	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			du[i][j]=1;
		}
	}
	
	/*	IMPLEMENTAÇÃO DA MATRIZ DITHER	*/
	if(n==2){
		dn[0][0] = 0; 
		dn[0][1] = 2; 
		dn[1][0] = 3; 
		dn[1][1] = 1; 
		return dn;
	}else{
		
		/*	DAUX - MATRIZ DITHER DIMENSAO N	*/
		int** daux = new int*[n];
		for(int i=0; i<n; i++){
			daux[i] = new int[n];
		}
		/*	DAUX1 - MATRIZ DITHER DIMENSAO N/2	*/
		int** daux1 = new int*[n];
		for(int i=0; i<n; i++){
			daux1[i] = new int[n];
		}
		/*	DAUX2 - MATRIZ DITHER DIMENSAO N/2	*/
		int** daux2 = new int*[n];
		for(int i=0; i<n; i++){
			daux2[i] = new int[n];
		}
		/*	DAUX3 - MATRIZ DITHER DIMENSAO N/2	*/
		int** daux3 = new int*[n];
		for(int i=0; i<n; i++){
			daux3[i] = new int[n];
		}
		/*	DAUX4 - MATRIZ DITHER DIMENSAO N/2	*/
		int** daux4 = new int*[n];
		for(int i=0; i<n; i++){
			daux4[i] = new int[n];
		}
		
		/*	MATRIZ DAUX RECEBE A MATRIZ DITHER RECURSIVA	*/
		daux = dither(n/2);
		
		/*	PRIMEIRO QUADRANTE DA MATRIZ DITHER N	*/
		for(int a=0;a<n/2;a++){
			for(int b=0;b<n/2;b++){
				daux1[a][b]=4*daux[a][b];
			}
		}
		
		/*	SEGUNDO QUADRANTE DA MATRIZ DITHER N	*/
		for(int a=0;a<n/2;a++){
			for(int b=0;b<n/2;b++){
				daux2[a][b]=2*du[a][b]+daux1[a][b];
			}
		}
		
		/*	TERCEIRO QUADRANTE DA MATRIZ DITHER N	*/
		for(int a=0;a<n/2;a++){
			for(int b=0;b<n/2;b++){
				daux3[a][b]=3*du[a][b]+daux1[a][b];
			}
		}
		
		/*	QUARTO QUADRANTE DA MATRIZ DITHER N	*/
		for(int a=0;a<n/2;a++){
			for(int b=0;b<n/2;b++){
				daux4[a][b]=du[a][b]+daux1[a][b];
			}
		}
		
		/*	FORMAÇÃO DA MATRIZ DITHER A PARTIR DAS MATRIZES AUXILIARES	*/
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if((i<(n/2))&&(j<(n/2))){
					dn[i][j]=daux1[i%(n/2)][j%(n/2)];
				}
				if((i<(n/2))&&(j>=(n/2))){
					dn[i][j]=daux2[i%(n/2)][j%(n/2)];
				}
				if((i>=(n/2))&&(j<(n/2))){
					dn[i][j]=daux3[i%(n/2)][j%(n/2)];
				}
				if((i>=(n/2))&&(j>=(n/2))){
					dn[i][j]=daux4[i%(n/2)][j%(n/2)];
				}
			}
		}
	}
	
	return dn;
}