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

    std::unordered_map<string,std::pair<vector< vector<int> >, string> > closed_list;
    std::multimap<int,std::pair<vector< vector<int> >, string> > open_list;


    string pai;
    int difmatrizatual = diferencaMatriz(matrizatual);
    std::pair<vector< vector<int> >, string> segundoargumento;
    segundoargumento = std::make_pair(matrizatual, pai);
    std::pair<int, std::pair<vector< vector<int> >, string> > inserir;
    inserir = std::make_pair(difmatrizatual, segundoargumento);

    open_list.insert(inserir);

    while(!open_list.empty()){

        std::multimap<int,std::pair<vector< vector<int> >, string> >::iterator multiatual = open_list.begin();

        std::pair<vector< vector<int> >, string>  par2 = multiatual->second;
        vector< vector<int> > matrizatualx = par2.first;
        int difmatrizatual = diferencaMatriz(matrizatualx);
        string stringatual = transformaMatrizString(matrizatualx);

        cout<<"Dif matriz atual: "<<difmatrizatual<<"\n";
        if (difmatrizatual == 0){
            string atualstring = transformaMatrizString(matrizatualx);
            std::pair<vector< vector<int> >, string> acharPai;
            acharPai = multiatual->second;
            pai = acharPai.second;
            std::pair<std::string,std::pair<vector< vector<int> >, string> > estadofinalizado;
            std::pair<vector< vector<int> >, string>  valores;
            valores = std::make_pair(matrizatualx, pai);
            estadofinalizado = make_pair(atualstring, valores);
            closed_list.insert(estadofinalizado);
            printpassos(closed_list, stringatual);
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
            std::pair<std::string,std::pair<vector< vector<int> >, string> > estadofinalizado;
            std::pair<vector< vector<int> >, string>  valores;
            valores = std::make_pair(matrizatualx, "");
            estadofinalizado = make_pair(atualstring, valores);
            closed_list.insert(estadofinalizado);
            }
        else{
            string atualstring = transformaMatrizString(matrizatualx);
            std::pair<vector< vector<int> >, string> acharPai;
            acharPai = multiatual->second;
            pai = acharPai.second;
            std::pair<std::string,std::pair<vector< vector<int> >, string> > estadofinalizado;
            std::pair<vector< vector<int> >, string>  valores;
            valores = std::make_pair(matrizatualx, pai);
            estadofinalizado = make_pair(atualstring, valores);
            closed_list.insert(estadofinalizado);
        }



        if(x0>=0){

            vector< vector<int> > matriz(4, vector<int>(4));


            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x0][y];
            matriz[x0][y] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);

            std::unordered_map<string,std::pair<vector< vector<int> >, string> >::iterator got1 = closed_list.find(possibilidade);


            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, string> >::iterator searchpai = closed_list.find(stringatual);



                int difmatrizpossibilidade = diferencaMatriz(matriz) + 1;



                std::pair<vector< vector<int> >, string> segundoargumento;
                segundoargumento = std::make_pair(matriz, stringatual);
                std::pair<int, std::pair<vector< vector<int> >, string> > inserir;
                inserir = std::make_pair(difmatrizpossibilidade, segundoargumento);
                open_list.insert(inserir);

            }
        }
        if(x1<=3){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x1][y];
            matriz[x1][y] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<string,std::pair<vector< vector<int> >, string> >::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, string> >::iterator searchpai = closed_list.find(stringatual);



                int difmatrizpossibilidade = diferencaMatriz(matriz) +1;


                std::pair<vector< vector<int> >, string> segundoargumento;
                segundoargumento = std::make_pair(matriz, stringatual);
                std::pair<int, std::pair<vector< vector<int> >, string> > inserir;
                inserir = std::make_pair(difmatrizpossibilidade, segundoargumento);
                open_list.insert(inserir);

            }
        }
        if(y0>=0){
            vector< vector<int> > matriz(4, vector<int>(4));
            matriz = matrizatualx;
            matriz[x][y] = matrizatualx[x][y0];
            matriz[x][y0] = matrizatualx[x][y];
            string possibilidade = transformaMatrizString(matriz);
            std::unordered_map<string,std::pair<vector< vector<int> >, string> >::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, string> >::iterator searchpai = closed_list.find(stringatual);

                int difmatrizpossibilidade = diferencaMatriz(matriz)+1;

                std::pair<vector< vector<int> >, string> segundoargumento;
                segundoargumento = std::make_pair(matriz, stringatual);
                std::pair<int, std::pair<vector< vector<int> >, string> > inserir;
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
            std::unordered_map<string,std::pair<vector< vector<int> >, string> >::iterator got1 = closed_list.find(possibilidade);
            if (got1==closed_list.end()){
                std::unordered_map<std::string,std::pair<vector< vector<int> >, string> >::iterator searchpai = closed_list.find(stringatual);


                int difmatrizpossibilidade = diferencaMatriz(matriz)+1;

                std::pair<vector< vector<int> >, string> segundoargumento;
                segundoargumento = std::make_pair(matriz, stringatual);
                std::pair<int, std::pair<vector< vector<int> >, string> > inserir;
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

    vector< vector<int> > teste = {{1, 12, 11, 10},
                                     {0, 2, 13, 8},
                                     {5, 4, 9, 15},
                                     {3, 6, 14, 7}};



    principal(teste, 0);
    return 0;
}
