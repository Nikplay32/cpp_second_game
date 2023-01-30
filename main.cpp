#include <iostream>

class Enemy {
public:
    int hp;
    int enemyAttack;
    int enemyUltimate;

void GetStats(int number) {
    hp = rand() % 10 + 1;
    enemyAttack = rand() % 5 + 1;
    enemyUltimate = rand() % 8 + 1;
    std::cout << "Attack stats:" << enemyAttack << std::endl;
    std::cout << "Ultimate attack:" << enemyUltimate << std::endl;
    std::cout << "Health Points:" << hp << std::endl;
    std::cout << "-----------------" << std::endl;
  }
};

class War {
public:
  Enemy Sparta[2];
  Enemy Afins[2];
  int spartahp, afinshp, warrior1[2], warrior2[2];
  int move, choose; 

void Fight() {
  std::cout << "---------------" << std::endl;
  std::cout << "Sparta warriors and stats:" << std::endl;
  std::cout << "---------------" << std::endl;
  for (int i = 0; i < 2; i++){
    Sparta[i].GetStats(i);
  }
  std::cout << "Afins warriors and stats:" << std::endl;
  std::cout << "---------------" << std::endl;
  for (int i = 0; i < 2; i++){
    Afins[i].GetStats(i);
  }
  std::cout << "Please choose your side - Sparta(1) or Afins(2)"<< std::endl;
  std::cin >> move;
  std::cout << "---------------" << std::endl;
  if (move == 1){
    for (int i = 0; i < 2; i++){
      while (Sparta[i].hp > 0 && Afins[i].hp > 0){
        std::cout << "Choose the attack, which you wanna do: " << std::endl;
        std::cin >> choose;
        std::cout << "---------------" << std::endl;
        if(choose == 1){
          std::cout << "You are attacking Afins" << std::endl;
          Afins[i].hp -= Sparta[i].enemyAttack;
          std::cout << Afins[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
          std::cout << "Afins is attacking your soldier" << std::endl;
          Sparta[i].hp -= Afins[i].enemyAttack;
          std::cout << Sparta[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
        }
        if(choose == 2){
          std::cout << "You are attacking Afins with Ultimate" << std::endl;
          Afins[i].hp -= Sparta[i].enemyUltimate;
          std::cout << Afins[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
          std::cout << "Afins is attacking your soldier" << std::endl;
          Sparta[i].hp -= Afins[i].enemyUltimate;
          std::cout << Sparta[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
        }
      
      }
    if(Afins[i].hp <= 0){
        std::cout << "In fight won your soldier. Congratilations!"     << std::endl;
      std::cout << "---------------" << std::endl;
        warrior1[i] = Afins[i].hp;
    }
    else if(Sparta[i].hp <= 0){
        std::cout << "You lose" << std::endl;
        std::cout << "---------------" << std::endl;
        warrior2[i] = Sparta[i].hp;
    }
    }
  } else {
    for (int i = 0; i < 2; i++){
      while (Sparta[i].hp > 0 && Afins[i].hp > 0){
        std::cout << "Choose the attack, which you wanna do: " << std::endl;
        std::cin >> choose;
        std::cout << "---------------" << std::endl;
        if(choose == 1){
          std::cout << "You are attacking Sparta" << std::endl;
          Sparta[i].hp -= Afins[i].enemyAttack;
          std::cout << Sparta[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
          std::cout << "Sparta is attacking your soldier" << std::endl;
          Afins[i].hp -= Sparta[i].enemyAttack;
          std::cout << Afins[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
        }
        if(choose == 2){
          std::cout << "You are attacking Sparta with Ultimate" << std::endl;
          Sparta[i].hp -= Afins[i].enemyUltimate;
          std::cout << Sparta[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
          std::cout << "Sparta is attacking your soldier" << std::endl;
          Afins[i].hp -= Sparta[i].enemyUltimate;
          std::cout << Afins[i].hp << " HP" << std::endl;
          std::cout << "---------------" << std::endl;
        }
      }
    if(Sparta[i].hp <= 0){
      std::cout << "In fight won your soldier. Congratilations!"     << std::endl;
      std::cout << "---------------" << std::endl;
      warrior1[i] = Sparta[i].hp;
    }
    else if(Afins[i].hp <= 0){
      std::cout << "You lose" << std::endl;
      std::cout << "---------------" << std::endl;
      warrior2[i] = Afins[i].hp;
    }
  }
  }
  for (int i = 0; i < 2; i++){
    spartahp += warrior1[i];
    afinshp += warrior2[i];
  }
  if (afinshp > spartahp){
    std::cout << "It's an afin win!";
  }
  else if (spartahp > afinshp){
    std::cout << "It's a sparta win!";
  }
  else{
    std::cout << "It's a draw";
  }
  }
};


int main(){
  
srand(time(NULL));
  
std::cout << "██████╗  █████╗ ████████╗████████╗██╗     ███████╗"<< std::endl;
std::cout << "██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝"<< std::endl;
std::cout << "██████╔╝███████║   ██║      ██║   ██║     █████╗  "<< std::endl;
std::cout << "██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  "<< std::endl;
std::cout << "██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗"<< std::endl;
std::cout << "╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝"<< std::endl;

std::cout << "Fight wins soldier that strikes and kills first. Then afins or sparta wins in health fight. Let's fight!" << std::endl;
  
War War;
War.Fight(); 
}
