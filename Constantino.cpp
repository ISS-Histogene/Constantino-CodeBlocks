#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

/*
 *
 */

string transformaMatrizString(vector< vector<int> > matriz){

    int a;
    int b;
    string matrizstring = "";
    for(a=0; a<4; a++){
        for(b=0; b<4;b++){
            ostringstream convert;
            convert << matriz[a][b];
            string elemento = convert.str();
            matrizstring += elemento;
            matrizstring += " ";
        }
    }
    return matrizstring;
}

vector< vector<int> > transformaStringMatriz(string matriz){
    vector< vector<int> > retorno(4, vector<int>(4));
    std::stringstream sstr(matriz);
    int x = 0;
    int y = 0;
    int i;
    while (sstr >> i){
        if(y==4){
            x += 1;
            y= 0 ;
        }
        retorno[x][y] = i;
        y++;
    }
    return retorno;
}

void localizazero(vector< vector<int> >matriz, vector<int> &zero){
    for (int x=0; x < 4; x++){
        for (int y=0; y < 4; y++){
            if (matriz[x][y] == 0){
                zero.push_back(x);
                zero.push_back(y);
            }
        }
     }
}

int diferencaMatriz(vector< vector<int> >matriz){
    vector< vector<int> > original                   = {{1, 5, 9, 13},
                                                        {2, 6, 10, 14},
                                                        {3, 7, 11, 15},
                                                        {4, 8, 12, 0}};

    vector< vector<int> > original2                  = {{1, 4, 7},
                                                        {2, 5, 8},
                                                        {3, 6, 0}};


    int dif = 0;
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

void principal(vector< vector<int> > teste2, int movimentos){
    string retorno1;
    string retorno2;
    string retorno3;
    string retorno4;

    std::unordered_map<string,int> closed_list;
    std::multimap<int,std::pair<vector< vector<int> >, string> > open_list;
    int difteste = diferencaMatriz(teste2);

    string estadoanterior = "";
    string pai;
    std::pair<vector< vector<int> >, string> segundo;
    std::pair<int, std::pair<vector< vector<int> >, string> > inserir;
    inserir = std::make_pair(difteste, teste2);
    open_list.insert(inserir);
    int counter = 0;
    while(!open_list.empty()){

        auto primeiro = open_list.cbegin();
        std::pair<vector< vector<int> >, string>  par2 = primeiro->second;
        vector< vector<int> > teste = par2.first;
        open_list.erase(primeiro);
        cout<<"Custo: "<<primeiro->first<<"\n";

        cout<<"Continuar? R: ";
        int opt;
        cin>>opt;
        if(opt==1){
            break;
        }
        int t;
        for (t=0; t<4; t++){
            cout<<teste[t][0]<<" "<<teste[t][1]<<" "<<teste[t][2]<<" "<<teste[t][3]<<"\n";
        }
        cout<<"\n\n";
        movimentos++;
        vector<int> zero;
        localizazero(teste, zero);
        int x = zero[0];
        int y = zero[1];
        int x0 = x-1;
        int x1 = x+1;
        int y0 = y-1;
        int y1 = y+1;
        cout<<"X:"<<x<<" "<<"Y:"<<y<<" "<<"X0:"<<x0<<" "<<"Y0:"<<y0<<" "<<"X1:"<<x1<<" "<<"Y1:"<<y1<<"\n";
        if(x0>=0){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = teste;
            matriz[x][y] = teste[x0][y];
            matriz[x0][y] = teste[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<std::string,int>::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                    int dif = diferencaMatriz(matriz);
                    int total = dif + counter;
                    string pai = transformaMatrizString(teste);
                    std::pair<vector< vector<int> >, string> segundo;
                    std::pair<int,segundo> inserir (total, matriz);
                    open_list.insert(inserir);
                    std::pair<std::string,vector< vector<int> >> estadoadicionado (possibilidade, teste);
                    closed_list.insert(estadoadicionado);
            }
            else{
                cout<<"Caiu aqui"<<"\n";
            }
        }
        if(x1<=3){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = teste;
            matriz[x][y] = teste[x1][y];
            matriz[x1][y] = teste[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<std::string,int>::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                    int dif = diferencaMatriz(matriz);
                    int total = dif + counter;
                    string pai = transformaMatrizString(teste);
                    std::pair<vector< vector<int> >, pai> segundo;
                    std::pair<int,segundo> inserir (total, matriz);
                    open_list.insert(inserir);
                    std::pair<std::string,vector< vector<int> >> estadoadicionado (possibilidade, teste);
                    closed_list.insert(estadoadicionado);
            }
            else{
                cout<<"Caiu aqui"<<"\n";
            }
        }
        if(y0>=0){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = teste;
            matriz[x][y] = teste[x][y0];
            matriz[x][y0] = teste[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<std::string,int>::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                    int dif = diferencaMatriz(matriz);
                    int total = dif + counter;
                    string pai = transformaMatrizString(teste);
                    std::pair<vector< vector<int> >, pai> segundo;
                    std::pair<int,segundo> inserir (total, matriz);
                    open_list.insert(inserir);
                    std::pair<std::string,vector< vector<int> >> estadoadicionado (possibilidade, teste);
                    closed_list.insert(estadoadicionado);
            }
            else{
                cout<<"Caiu aqui"<<"\n";
            }
        }
        if(y1<=3){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = teste;
            matriz[x][y] = teste[x][y1];
            matriz[x][y1] = teste[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<std::string,int>::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                    int dif = diferencaMatriz(matriz);
                    int total = dif + counter;
                    string pai = transformaMatrizString(teste);
                    std::pair<vector< vector<int> >, pai> segundo;
                    std::pair<int,segundo> inserir (total, matriz);
                    open_list.insert(inserir);
                    std::pair<std::string,vector< vector<int> >> estadoadicionado (possibilidade, teste);
                    closed_list.insert(estadoadicionado);
            }
            else{
                cout<<"Caiu aqui"<<"\n";
            }
        }

        string atual = transformaMatrizString(teste);
        std::pair<std::string,vector< vector<int> >> estadofinalizado (atual, counter);
        closed_list.insert(estadofinalizado);
        difteste = diferencaMatriz(teste);
        if (difteste==8){
            break;
        }

    }

}




int main(int argc, char** argv) {

    vector< vector<int> > teste2 = {{0, 13, 9, 2},
                                    {4, 5, 8, 6},
                                    {3, 7, 12, 10},
                                    {15, 1, 14, 11}};

    vector< vector<int> > teste = {{1, 12, 11, 10},
                                     {0, 2, 13, 8},
                                     {5, 4, 9, 15},
                                     {3, 6, 14, 7}};



    principal(teste, 0);
    return 0;
}
