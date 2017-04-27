#include<iostream>
using namespace std;

struct Animal{
  int animalType; // 0 - dog, 1 - cat
  int arrival;
  Animal* next;
};

class Shelter{
  int arrival = 0;
  Animal* oldestDog = nullptr;
  Animal* newestDog = nullptr;
  Animal* oldestCat = nullptr;
  Animal* newestCat = nullptr;
public:
    void enqueue(Animal* a);
    Animal* dequeueDog();
    Animal* dequeueCat();
    Animal* dequeueAny();
};

void Shelter::enqueue(Animal* a){
  if(!a){return;}
  a->arrival = arrival++;
  switch(a->animalType){
    case 0:
      if(!oldestDog){
        oldestDog = a;
        newestDog = a;
      }
      else{
        newestDog->next = a;
        newestDog = a;
      }
      break;
    case 1:
      if(!oldestCat){
        oldestCat = a;
        newestCat = a;
      }
      else{
        newestCat->next = a;
        newestCat = a;
      }
      break;
    default:
      return;
  }
}

Animal* Shelter::dequeueDog(){
  Animal* a = oldestDog;
  if(oldestDog){oldestDog = oldestDog->next;}
  return a;
}

Animal* Shelter::dequeueCat(){
  Animal* a = oldestCat;
  if(oldestCat){oldestCat = oldestCat->next;}
  return a;
}

Animal* Shelter::dequeueAny(){
  if(oldestDog && oldestCat){
    if(oldestDog->arrival < oldestCat->arrival){return dequeueDog();}
    else{return dequeueCat();}
  }
  if(oldestDog){return dequeueDog();}
  if(oldestCat){return dequeueCat();}

  return nullptr;
}

int main(){
  Shelter s;
  for(int i = 0; i < 10; i++){
    Animal* a = new Animal;
    a->animalType = i%2;
    s.enqueue(a);
  }
  Animal* cat = s.dequeueCat();
  cout << "cat: " << endl;
  cout << cat->animalType << endl;
  cout << cat->arrival << endl;
  cout << "dog1: " << endl;
  Animal* dog1 = s.dequeueAny();
  cout << dog1->animalType << endl;
  cout << dog1->arrival << endl;
  cout << "dog2: " << endl;
  Animal* dog2 = s.dequeueDog();
  cout << dog2->animalType << endl;
  cout << dog2->arrival << endl;
  return 0;
}
