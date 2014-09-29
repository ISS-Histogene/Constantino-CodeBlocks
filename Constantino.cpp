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

void printpassos(std::unordered_map<string,std::pair<vector< vector<int> >, string> > lista_fechada, string atual){
    if (atual != ""){

        std::unordered_map<string,std::pair<vector< vector<int> >, string> >::iterator got1 = lista_fechada.find(atual);
        std::pair<vector< vector<int> >, string> passo1 = got1->second;
        string paifinal = passo1.second;
        printpassos(lista_fechada, paifinal);
        cout<<"Proximo passo? R: ";
        int opt;
        cin>>opt;
        if (opt!=1){
            vector< vector<int> > matrizfinal = passo1.first;
            int t;
            for (t=0; t<4; t++){
                cout<<matrizfinal[t][0]<<" "<<matrizfinal[t][1]<<" "<<matrizfinal[t][2]<<" "<<matrizfinal[t][3]<<"\n";
            }
            cout<<"\n\n\n";
        }

    }




}

void principal(vector< vector<int> > matrizatual, int movimentos){
    string retorno1;
    string retorno2;
    string retorno3;
    string retorno4;

    std::unordered_map<string,std::pair<vector< vector<int> >, int> > closed_list;
    std::multimap<int,std::pair<vector< vector<int> >, int> > open_list;


    string pai;
    int difmatrizatual = diferencaMatriz(matrizatual);

    std::pair<vector< vector<int> >, int> segundoargumento;
    segundoargumento = std::make_pair(matrizatual, 0);
    std::pair<int, std::pair<vector< vector<int> >, int> > inserir;
    inserir = std::make_pair(difmatrizatual, segundoargumento);

    open_list.insert(inserir);

    while(!open_list.empty()){

        std::multimap<int,std::pair<vector< vector<int> >, int> >::iterator multiatual = open_list.begin();

        std::pair<vector< vector<int> >, int>  par2 = multiatual->second;
        vector< vector<int> > matrizatualx = par2.first;
        int difmatrizatual = diferencaMatriz(matrizatualx);
        string stringatual = transformaMatrizString(matrizatualx);
        int atualizar = par2.second + 1;
        int valor = par2.second;

        cout<<"Dif matriz atual: "<<difmatrizatual<<"\n";
        if (difmatrizatual == 0){
            int valor;
            string atualstring = transformaMatrizString(matrizatualx);
            std::pair<vector< vector<int> >, int> acharvalor= multiatual->second;
            valor = acharvalor.second;

            cout<<"Movimentos: "<<valor;
            /*
            acharPai = multiatual->second;
            pai = acharPai.second;
            std::pair<std::string,std::pair<vector< vector<int> >, string> > estadofinalizado;
            std::pair<vector< vector<int> >, string>  valores;
            valores = std::make_pair(matrizatualx, pai);
            estadofinalizado = make_pair(atualstring, valores);
            closed_list.insert(estadofinalizado);
            printpassos(closed_list, stringatual);
            */
            break;
        }

        cout<<"\n\n";
        //LOCALIZA O ZERO
        vector<int> zero;
        localizazero(matrizatualx, zero);
        int x = zero[0];
        int y = zero[1];
        int x0 = x-1;
        int x1 = x+1;
        int y0 = y-1;
        int y1 = y+1;
        cout<<"X:"<<x<<" "<<"Y:"<<y<<" "<<"X0:"<<x0<<" "<<"Y0:"<<y0<<" "<<"X1:"<<x1<<" "<<"Y1:"<<y1<<"\n";

        if (closed_list.empty()){
            string atualstring = transformaMatrizString(matrizatualx);
            std::pair<std::string,std::pair<vector< vector<int> >, int> > estadofinalizado;
            std::pair<vector< vector<int> >, int>  valores;
            valores = std::make_pair(matrizatualx, 0);
            estadofinalizado = make_pair(atualstring, valores);
            closed_list.insert(estadofinalizado);
            }
        else{
            string atualstring = transformaMatrizString(matrizatualx);
            std::pair<vector< vector<int> >, string> acharPai;
            acharPai = multiatual->second;
            pai = acharPai.second;

            std::unordered_map<std::string,std::pair<vector< vector<int> >, int> >::iterator searchpai = closed_list.find(pai);
            if (searchpai != closed_list.end()){
                std::pair<vector< vector<int> >, int> passo1 = searchpai->second;
                int valoranterior = passo1.second;
                cout<<"teste";
                if (valoranterior+1 < atualizar){
                    std::pair<std::string,std::pair<vector< vector<int> >, int> > estadofinalizado;
                    std::pair<vector< vector<int> >, int>  valores;
                    valores = std::make_pair(matrizatualx, valoranterior+1);
                    estadofinalizado = make_pair(atualstring, valores);
                    closed_list.insert(estadofinalizado);
                }
            }
            else{
                std::pair<std::string,std::pair<vector< vector<int> >, int> > estadofinalizado;
                std::pair<vector< vector<int> >, int>  valores;
                valores = std::make_pair(matrizatualx, atualizar);
                estadofinalizado = make_pair(atualstring, valores);
                closed_list.insert(estadofinalizado);
            }
        }



        if(x0>=0){

            vector< vector<int> > matriz(4, vector<int>(4));


            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x0][y];
            matriz[x0][y] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);

            std::unordered_map<string,std::pair<vector< vector<int> >, int> >::iterator got1 = closed_list.find(possibilidade);


            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, int> >::iterator searchpai = closed_list.find(stringatual);

                int difmatrizpossibilidade = diferencaMatriz(matriz) + 1;

                std::pair<vector< vector<int> >, int> segundoargumento;
                segundoargumento = std::make_pair(matriz, atualizar);
                std::pair<int, std::pair<vector< vector<int> >, int> >inserir;
                inserir = std::make_pair(difmatrizpossibilidade, segundoargumento);
                open_list.insert(inserir);
            }
            else{

            }
        }
        if(x1<=3){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x1][y];
            matriz[x1][y] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<string,std::pair<vector< vector<int> >, int> >::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, int> >::iterator searchpai = closed_list.find(stringatual);

                int difmatrizpossibilidade = diferencaMatriz(matriz) +1;

                std::pair<vector< vector<int> >, int> segundoargumento;
                segundoargumento = std::make_pair(matriz, atualizar);
                std::pair<int, std::pair<vector< vector<int> >, int> > inserir;
                inserir = std::make_pair(difmatrizpossibilidade, segundoargumento);
                open_list.insert(inserir);

            }
            else{
                std::pair<vector< vector<int> >, int>  passo1 = got->second;
                int valoranterior = passo1.second;
            }
        }
        if(y0>=0){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x][y0];
            matriz[x][y0] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<string,std::pair<vector< vector<int> >, int> >::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, int> >::iterator searchpai = closed_list.find(stringatual);

                int difmatrizpossibilidade = diferencaMatriz(matriz)+1;

                std::pair<vector< vector<int> >, int> segundoargumento;
                segundoargumento = std::make_pair(matriz, atualizar);
                std::pair<int, std::pair<vector< vector<int> >, int> > inserir;
                inserir = std::make_pair(difmatrizpossibilidade, segundoargumento);
                open_list.insert(inserir);
            }
        }
        if(y1<=3){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x][y1];
            matriz[x][y1] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<string,std::pair<vector< vector<int> >, int> >::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, int> >::iterator searchpai = closed_list.find(stringatual);


                int difmatrizpossibilidade = diferencaMatriz(matriz)+1;

                std::pair<vector< vector<int> >, int> segundoargumento;
                segundoargumento = std::make_pair(matriz, atualizar);
                std::pair<int, std::pair<vector< vector<int> >, int> > inserir;
                inserir = std::make_pair(difmatrizpossibilidade, segundoargumento);
                open_list.insert(inserir);

            }
        }

        open_list.erase(multiatual);
    }

}




int main(int argc, char** argv) {

    vector< vector<int> > teste2 = {{0, 13, 9, 2},
                                    {4, 5, 8, 6},
                                    {3, 7, 12, 10},
                                    {15, 1, 14, 11}};

    vector< vector<int> > caso1 = {{1, 12, 11, 10},
                                     {0, 2, 13, 8},
                                     {5, 4, 9, 15},
                                     {3, 6, 14, 7}};

    vector< vector<int> > caso2 = {{1, 6, 0, 11},
                                   {2, 9, 13, 5},
                                   {3, 7, 14, 10},
                                   {4, 8, 12, 15}};

    vector< vector<int> > caso3 = {{9, 8, 0, 14},
                                   {7, 6, 5, 1},
                                   {2, 4, 11, 10},
                                   {3, 12, 13, 15}};

    vector< vector<int> > caso4 = {{1, 13, 7, 10},
                                    {2, 0, 12, 11},
                                    {3, 14, 6, 9},
                                    {8, 4, 5, 15}};

    vector< vector<int> > caso5 = {{4, 7, 0, 13},
                                   {5, 9, 10, 14},
                                   {6, 11, 3, 1},
                                   {8, 2, 15, 12}};

    principal(caso1, 0);
    return 0;
}
