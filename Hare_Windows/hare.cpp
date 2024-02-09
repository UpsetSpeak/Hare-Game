#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


void resetBoard(std::string board_space[11], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt);
void printBoard(std::string board_space[11], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt);
void dogMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt, int &verify_victory_dog, int verify_victory_rbt);
void rabbitMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int &position_rbt, int &verify_victory_dog, int verify_victory_rbt);
void botDogMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt, int &verify_victory_dog, int verify_victory_rbt);
void botRbtMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int &position_rbt, int &verify_victory_dog, int &verify_victory_rbt);
void regras();





int main(){

std::string resposta;
int number_players=0;
int verify_victory_rbt = 1;
int verify_victory_dog = 1;
int position_dog[3] = {0,1,3};
int position_rbt = 10;
std::string RBT = " RBT";
std::string DOG[3] = {"DOG1", "DOG2", "DOG3"};
std::string board_space[11] = {"    ", "    ", "    ", "    ", "    ", "    ", "    ", "    ", "    ", "    ", "    "};

std::srand(static_cast<unsigned int>(std::time(nullptr)));

regras();

std::cout<<"Quantos jogadores? (esse jogo suporta apenas 2 jogadores)"<<'\n';   // checa quantas pessoas irao jogar
std::cin>>number_players;

while(number_players!=1&&number_players!=2){
    std::cout<<"Favor inserir um numero de jogadores valido (1 ou 2)"<<'\n';
    std::cin>>number_players;
}




switch (number_players)
{
case 1:
std::cout<<"voce gostaria de ser o coelho ou os cachorros?"<<'\n';  // checa qual jogador o usuario quer ser
std::cin>>resposta;
std::transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);

while(resposta!="coelho"&&resposta!="cachorros"&&resposta!="cachorro"){  // caso a entrada do usuario nao seja valida
    std::cout<<"favor inserir uma entrada valida"<<'\n';
    std::cin>>resposta;
    std::transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
}

resetBoard(board_space, DOG, RBT, position_dog, position_rbt);

if(resposta=="coelho"){     // comeco jogo coelho vs COM
    while(verify_victory_dog!=0&&verify_victory_rbt!=0){
        botDogMove(board_space, DOG, RBT, position_dog, position_rbt, verify_victory_dog, verify_victory_rbt);
        if(verify_victory_dog!=1){
    break;
}
rabbitMove(board_space, DOG, RBT, position_dog, position_rbt, verify_victory_dog, verify_victory_rbt);

switch (position_rbt){
case 1:
    verify_victory_rbt=0;
    break;
case 2:
    verify_victory_rbt=0;
    break;
case 3:
    verify_victory_rbt=0;
    break;
default:
    break;
}

    } // fim do jogo coelho VS com
}else if(resposta=="cachorros"||resposta=="cachorro"){ // comeco do jogo cachorro VS com


while(verify_victory_dog!=0&&verify_victory_rbt!=0){
        dogMove(board_space, DOG, RBT, position_dog, position_rbt, verify_victory_dog, verify_victory_rbt);
        if(verify_victory_dog!=1){
    break;
}
botRbtMove(board_space, DOG, RBT, position_dog, position_rbt, verify_victory_dog, verify_victory_rbt);

switch (position_rbt){
case 1:
    verify_victory_rbt=0;
    break;
case 2:
    verify_victory_rbt=0;
    break;
case 3:
    verify_victory_rbt=0;
    break;
default:
    break;
}

}// fim do jogo cachorro VS com



}


    break;
case 2: // comeco do jogo player vs player

    resetBoard(board_space, DOG, RBT, position_dog, position_rbt);

    while(verify_victory_dog!=0&&verify_victory_rbt!=0){
    
dogMove(board_space, DOG, RBT, position_dog, position_rbt, verify_victory_dog, verify_victory_rbt);


if(verify_victory_dog!=1){
    break;
}

rabbitMove(board_space, DOG, RBT, position_dog, position_rbt, verify_victory_dog, verify_victory_rbt);



switch (position_rbt){
case 1:
    verify_victory_rbt=0;
    break;
case 2:
    verify_victory_rbt=0;
    break;
case 3:
    verify_victory_rbt=0;
    break;
default:
    break;
}

}
    break;
default:
    break;
} // fim do jogo player vs player










printBoard(board_space, DOG, RBT, position_dog, position_rbt);

if(verify_victory_dog==0){
    std::cout<<"Dog wins"<<'\n';        // printa o vencedor
}else if(verify_victory_rbt==0){
    std::cout<<"Rbt wins"<<'\n';
}


    std::cout << "Pressione Enter para sair...";
    std::cin.ignore(); 
    std::cin.ignore();
    return 0;
}



void resetBoard(std::string board_space[11], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt){ // funcao resetar tabuleiro
    board_space[10] = RBT;
    board_space[0] = DOG[0];
    board_space[1] = DOG[1];
    board_space[3] = DOG[2];


printBoard(board_space, DOG, RBT, position_dog, position_rbt);


};



void printBoard(std::string board_space[11], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt){ // funcao printar tabuleiro







    std::cout<<"                  2_____        5_____        8_____                   |"<<'\n';
    std::cout<<"                  |"<<board_space[1]<<" | _____ |"<<board_space[4]<<" | _____ |"<<board_space[7]<<" |                  |"<<'\n';
    std::cout<<"  	         /|_____|       |_____|       |_____|\\                 |"<<'\n';
    std::cout<<"               /     |   \\         |       /     |     \\               |"<<'\n';
    std::cout<<"             /       |     \\       |     /       |       \\             |"<<'\n';
    std::cout<<"    1_____ /      3_____     \\  6_____ /      9_____       \\ _____11   |"<<'\n';
    std::cout<<"    |"<<board_space[0]<<" | _____ | "<<board_space[2]<<"| _____ |"<<board_space[5]<<" | _____ |"<<board_space[8]<<" | _____ |"<<board_space[10]<<" |    |"<<'\n';
    std::cout<<"    |_____|       |_____|       |_____|       |_____|       |_____|    |"<<'\n';
    std::cout<<"          \\          |       /     |   \\         |         /           |"<<'\n';
    std::cout<<"            \\        |     /       |     \\       |       /             |"<<'\n';
    std::cout<<"              \\   4_____ /      7_____     \\10 _____   /               |"<<'\n';
    std::cout<<"                \\ |"<<board_space[3]<<" | _____ |"<<board_space[6]<<" | _____ |"<<board_space[9]<<" |/                 |"<<'\n';
    std::cout<<"                  |_____|       |_____|       |_____|                  |"<<'\n';





};



void dogMove(std::string board_space[],std::string DOG[3], std::string RBT, int position_dog[], int position_rbt, int &verify_victory_dog, int verify_victory_rbt){

int which_dog;      // funcao movimentos player cachorro
int move;



std::cout<<"Qual cachorro gostaria de mover?(1, 2 ou 3)"<<'\n';
std::cin>>which_dog;
which_dog--;

while(which_dog!=0&&which_dog!=1&&which_dog!=2){
std::cout<<"Entrada invalida, favor selecionar um dos 3 cachorros (1, 2 ou 3)"<<'\n';
std::cout<<"Qual cachorro gostaria de mover?(1, 2 ou 3)"<<'\n';
std::cin>>which_dog;
which_dog--;
}




switch (position_dog[which_dog])
{
case 0:

    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=1&&move!=2&&move!=3){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;    
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    

    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;

 
    break;
case 1:                                             // movimentos permitidos a partir de casa X
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=4&&move!=2&&move!=5){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
}
    
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 2:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=1&&move!=3&&move!=5){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 3:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=2&&move!=5&&move!=6){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 4:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=5&&move!=7){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 5:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=4&&move!=6&&move!=7&&move!=8&&move!=9){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 6:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=5&&move!=9){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 7:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=8&&move!=10){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 8:
        std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=7&&move!=9&&move!=10){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 9:
    std::cout<<"Para onde?"<<'\n';
    std::cin>>move;
    move--;
        if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=8&&move!=10){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n'; 
        std::cout<<"Para onde?"<<'\n';
        std::cin>>move;
        move--;
        
    }
    board_space[position_dog[which_dog]]= "    ";
    board_space[move]=DOG[which_dog];
    position_dog[which_dog]=move;
    break;
case 10:
    break;
default:
    break;
}















printBoard(board_space, DOG, RBT, position_dog, position_rbt);


};



void rabbitMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int &position_rbt, int &verify_victory_dog, int verify_victory_rbt){

int move;

                            // funcao movimento player coelho

switch (position_rbt)
{
case 10:                    // movimentos permitidos a partir de casa X
    if(board_space[9]!="    "&&board_space[8]!="    "&&board_space[7]!="    "){
        verify_victory_dog=0;
       
        break;
    }
    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }

    while(move!=9 && move!=8 && move!=7){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
            }
    

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    
    break;
case 9:

    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=8 && move!=5 && move!=6&&move!=10){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    break;
case 8:

    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=10 && move!=7 && move!=5&&move!=9){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    break;
case 7:

    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }

    while(move!=10 && move!=8 && move!=5&&move!=4){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    break;
case 6:
  if(board_space[9]!="    "&&board_space[5]!="    "&&board_space[3]!="    "){
        verify_victory_dog=0;
        
        break;
    }
    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }
    while(move!=9 && move!=5 && move!=3){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    break;
case 5:
    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    
    if (board_space[move] != "    ") {
        move=0;
        }

    while(move!=8 && move!=9 && move!=7&&move!=6&&move!=4&&move!=3&&move!=2&&move!=1){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    break;
case 4:
  if(board_space[7]!="    "&&board_space[5]!="    "&&board_space[1]!="    "){
       verify_victory_dog=0;
        
        break;
    }
    std::cout<<"Coelho para onde?"<<'\n';
    std::cin>>move;
    move--;
    if (board_space[move] != "    ") {
        move=0;
        }

    while(move!=7 && move!=5 && move!=1){
        std::cout<<"Movimento invalido, favor inserir um movimento valido"<<'\n';
        std::cin>>move;
        move--;
    if (board_space[move] != "    ") {
        move=0;
        }else{
            break;
        }
    }

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
    break;
case 3:
    verify_victory_rbt=0;
    break;
case 2:
    verify_victory_rbt=0;
    break;
case 1:
    verify_victory_rbt=0;
    break;
case 0:
    break;
default:
    break;
}
  




printBoard(board_space, DOG, RBT, position_dog, position_rbt);

    



};


void botDogMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int position_rbt, int &verify_victory_dog, int verify_victory_rbt){


bool loop=true;                 // funcao movimento cachorro bot


while(loop){

int which_dog;
int move;
which_dog = std::rand() % 3;


switch (position_dog[which_dog])        // geracao de movimento aleatorio e verificacao de permissao de movimento
{
case 0:
    move = std::rand()%12;

    if (board_space[move] == "    "&&(move==1||move==2||move==3)) {
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
    }

 
    break;
case 1:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==4||move==2||move==5)) {
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }

    


    break;
case 2:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==1||move==3||move==5)) {
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    
    


    break;
case 3:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==2||move==5||move==6)) {
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }

    


    break;
case 4:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==5||move==7)) {
        
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    break;
case 5:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==4||move==6||move==7||move==8||move==9)) {
        
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    break;
case 6:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==5||move==9)) {
        
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    break;
case 7:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==8||move==10)) {
        
        
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    break;
case 8:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==7||move==9||move==10)) {
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    break;
case 9:
    move = std::rand()%12;
    if (board_space[move] == "    "&&(move==8||move==10)) {
            board_space[position_dog[which_dog]]= "    ";
            board_space[move]=DOG[which_dog];
            position_dog[which_dog]=move;

            loop = false;
        }
    break;
case 10:
    break;
default:
    break;
}


}
printBoard(board_space, DOG, RBT, position_dog, position_rbt);



}




void botRbtMove(std::string board_space[], std::string DOG[3], std::string RBT, int position_dog[], int &position_rbt, int &verify_victory_dog, int &verify_victory_rbt){

bool loop = true;               // funcao movimento bot coelho

while(loop==true){
int move;


switch (position_rbt)                   // geracao de movimento aleatorio e verificacao de permissao de movimento
{
case 10:
    if(board_space[9]!="    "&&board_space[8]!="    "&&board_space[7]!="    "){
        verify_victory_dog=0;
        loop = false;
        break;
    }

    move=std::rand()%12;

    if (board_space[move] == "    "&&(move==9 || move==8 || move==7)) {

    board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
        loop=false;
        }

    
    break;
case 9:
    move=std::rand()%12;

    if (board_space[move] == "    "&&(move==8 || move==5 || move==6||move==10)) {
     board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
        loop=false;
        }
    break;
case 8:

    move=std::rand()%12;
    if (board_space[move] == "    "&&(move==10 || move==7 || move==5||move==9)) {
     board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
        loop=false;
        }
    break;
case 7:

    move=std::rand()%12;
    if (board_space[move] == "    "&&(move==10 || move==8 || move==5||move==4)) {
     board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
        loop=false;
        }
    break;
case 6:
  if(board_space[9]!="    "&&board_space[5]!="    "&&board_space[3]!="    "){
        verify_victory_dog=0;
        loop=false;
        break;
    }

    move=std::rand()%12;

    if (board_space[move] == "    "&&(move==9 || move==5 || move==3)) {
     board_space[position_rbt] = "    ";
    position_rbt = move;
    board_space[position_rbt] = RBT;
        loop=false;
        }
    break;
case 5:
    move=std::rand()%12;

    if (board_space[move] == "    "&&(move==8 || move==9 || move==7||move==6||move==4||move==3||move==2||move==1)) {
        board_space[position_rbt] = "    ";
        position_rbt = move;
        board_space[position_rbt] = RBT;
        loop=false;
        }
    break;
case 4:
  if(board_space[7]!="    "&&board_space[5]!="    "&&board_space[1]!="    "){
        verify_victory_dog=0;
        loop=false;
        break;
    }

    move=std::rand()%12;

    if (board_space[move] == "    "&&(move==7 || move==5 || move==1)) {
        board_space[position_rbt] = "    ";
        position_rbt = move;
        board_space[position_rbt] = RBT;
        loop=false;
        }
    break;
case 3:
    verify_victory_rbt=0;
    break;
case 2:
    verify_victory_rbt=0;
    break;
case 1:
    verify_victory_rbt=0;
    break;
case 0:
    break;
default:
    break;
}
  
}



printBoard(board_space, DOG, RBT, position_dog, position_rbt);

    





}



void regras(){

    std::cout<<"Hare and Hounds é um jogo simples que consiste em perseguir um coelho e o encurralar, ou fugir, caso você seja o coelho\n";
    std::cout<<"Os movimentos permitidos são demarcados pelas linhas que ligam as casa, porém os cachorros apenas se movem para frente e para o lado, o coelho se move livremente\n";
    std::cout<<"Pressione enter para continuar\n";
    std::cin.ignore();


}


