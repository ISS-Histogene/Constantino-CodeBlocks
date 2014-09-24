#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/*
 *
 */

void localizazero(int matriz[4][4], vector<int> &zero){
    for (int x=0; x < 4; x++){
        for (int y=0; y < 4; y++){
            if (matriz[x][y] == 0){
                zero.push_back(x);
                zero.push_back(y);
            }
        }
     }
}

int diferencaMatriz(int matriz[4][4]){
    int original[4][4] = {{1, 5, 9, 13},
                         {2, 6, 10, 14},
                         {3, 7, 11, 15},
                         {4, 8, 12, 0}};

    int dif = 0;
    int x = 0;
    int a;
    int b;
    for (a=0; a<4; a++){
        for(b=0; b<4; b++){
            if (original[a][b] != matriz[a][b]){
                dif++;
            }
        }
    }
    return dif;
}



int principal(int teste[4][4], int movimentos){
    int difteste = diferencaMatriz(teste);
    if (difteste == 0){
        cout<<movimentos;
        return 0;
    }
    movimentos++;
    const int rows = 4;
    const int columns = 4;
    vector<int> zero;
    localizazero(teste, zero);
    int x = zero[0];
    int y = zero[1];
    int x0 = x - 1;
    int x1 = x + 1;
    int y0 = y - 1;
    int y1 = y + 1;

    int dif1 = 40;
    int dif2 = 40;
    int dif3 = 40;
    int dif4 = 40;
    int tempObject;
    zero.clear();
    vector<int>().swap(zero);
    if (y==0){
            if (x==0){
                int matriz1[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
                matriz1[x1][y] = 0;
                matriz1[0][0] = teste[x1][y];
                dif1 = diferencaMatriz(matriz1);

                int matriz2[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
                matriz2[x][y1] = 0;
                matriz2[0][0] = teste[x][y1];
                dif2 = diferencaMatriz(matriz2);

                if (dif1 < dif2){
                    principal(matriz1, movimentos);
                }
                else{
                    principal(matriz2, movimentos);
                }


            }
            else if (x==3){
                int matriz1[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
                matriz1[x0][y] = 0;
                matriz1[0][0] = teste[x0][y];
                dif1 = diferencaMatriz(matriz1);

                int matriz2[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
                matriz2[x][y1] = 0;
                matriz2[0][0] = teste[x][y1];
                dif2 = diferencaMatriz(matriz2);

                if (dif1 < dif2){
                    principal(matriz1, movimentos);
                }
                else{
                    principal(matriz2, movimentos);
                }


            }
            else{
                int matriz1[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
                matriz1[x0][y] = 0;
                matriz1[x][y] = teste[x0][y];

                dif1 = diferencaMatriz(matriz1);

                int matriz2[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
                matriz2[x][y1] = 0;
                matriz2[x][y] = teste[x][y1];

                dif2 = diferencaMatriz(matriz2);

                int matriz3[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz3[0][0]);
                matriz3[x1][y] = 0;
                matriz3[x][y]= teste[x1][y];
                dif3 = diferencaMatriz(matriz3);

                if ((dif1 <= dif2) && (dif1 <= dif3)){
                    principal(matriz1, movimentos);
                }
                else if(dif2 <= dif3){
                    principal(matriz2, movimentos);
                }
                else{
                    principal(matriz3, movimentos);
                }

            }
    }
    else if(y==3) {
            if (x==0){
                int matriz1[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
                matriz1[x1][y] = 0;
                matriz1[0][3] = teste[x1][y];
                dif1 = diferencaMatriz(matriz1);

                int matriz2[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
                matriz2[x][y0] = 0;
                matriz2[0][3] = teste[x][y0];
                dif2 = diferencaMatriz(matriz2);

                if (dif1 < dif2){
                    principal(matriz1, movimentos);
                }
                else{
                    principal(matriz2, movimentos);
                }

            }
            else if (x==3){
                int matriz1[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
                matriz1[x0][y] = 0;
                matriz1[3][3] = teste[x0][y];
                dif1 = diferencaMatriz(matriz1);

                int matriz2[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
                matriz2[x][y0] = 0;
                matriz2[3][3] = teste[x][y0];
                dif2 = diferencaMatriz(matriz2);

                if (dif1 < dif2){
                    principal(matriz1, movimentos);
                }
                else{
                    principal(matriz2, movimentos);
                }

            }
            else{
                int matriz1[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
                matriz1[x0][y] = 0;
                matriz1[x][y] = teste[x0][y];
                dif1 = diferencaMatriz(matriz1);

                int matriz2[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
                matriz2[x][y0] = 0;
                matriz2[x][y] = teste[x][y0];
                dif2 = diferencaMatriz(matriz2);

                int matriz3[4][4] ;
                std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz3[0][0]);
                matriz3[x1][y] = 0;
                matriz3[x][y]= teste[x1][y];
                dif3 = diferencaMatriz(matriz3);

                if ((dif1 <= dif2) && (dif1 <= dif3)){
                    principal(matriz1, movimentos);
                }
                else if(dif2 <= dif3){
                    principal(matriz2, movimentos);
                }
                else{
                    principal(matriz3, movimentos);
                }

            }
        }
    else{
        int matriz1[4][4] ;
        std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz1[0][0]);
        matriz1[x0][y] = 0;
        matriz1[x][y] = teste[x0][y];
        dif1 = diferencaMatriz(matriz1);

        int matriz2[4][4] ;
        std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz2[0][0]);
        matriz2[x][y0] = 0;
        matriz2[x][y] = teste[x][y0];
        dif2 = diferencaMatriz(matriz2);

        int matriz3[4][4] ;
        std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz3[0][0]);
        matriz3[x1][y] = 0;
        matriz3[x][y]= teste[x1][y];
        dif3 = diferencaMatriz(matriz3);

        int matriz4[4][4] ;
        std::copy(&teste[0][0], &teste[0][0]+rows*columns,&matriz4[0][0]);
        matriz4[x][y1] = 0;
        matriz4[x][y] = teste[x][y1];
        dif4 = diferencaMatriz(matriz4);

        if ((dif1 <= dif2) && (dif1<=dif3) && (dif1<=dif4)){
            principal(matriz1, movimentos);
        }
        else if((dif2<=dif3) && (dif2<=dif4)){
            principal(matriz2, movimentos);
        }
        else if((dif3<=dif4)){
            principal(matriz3, movimentos);
        }
        else{
            principal(matriz4, movimentos);
        }
    }

}

int main(int argc, char** argv) {
    /*int teste[4][4] = {{1, 5, 9, 13},
                         {2, 6, 10, 14},
                         {3, 7, 11, 15},
                         {4, 8, 12, 0}};
    */
    int teste[4][4] = {{1, 12, 11, 10},
                       {0, 2, 13, 8},
                       {5, 4, 9, 15},
                       {3, 6, 14, 7}};


    principal(teste, 0);
    return 0;

}





