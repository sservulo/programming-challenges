#include<iostream>
using namespace std;

class RF{
  size_t count = 0;
  public:
  RF(){}
  RF(size_t count_): count(count_){}
  void addRef(){count++;}
  size_t release(){return --count;}
};

template<typename T>
class Smartpointer{
  T* data;
  RF* reference;
  public:
  Smartpointer(): data(nullptr), reference(nullptr){
    reference = new RF();
    reference->addRef();
  }

  Smartpointer(T& data_) : data(&data_), reference(nullptr){
    reference = new RF();
    reference->addRef();
  }

  Smartpointer(const Smartpointer<T>& sp): data(sp.data), reference(sp.reference){
    reference->addRef();
  }

  ~Smartpointer(){
    if(reference->release() == 0){
      delete data;
      delete reference;
    }
  }

  T& operator*(){
    return *data;
  }

  T* operator->(){
    return data;
  }

  Smartpointer<T>& operator=(const Smartpointer<T>& sp){
    if(this != &sp){
      if(reference->release() == 0){
        delete data;
        delete reference;
      }
      data = sp.data;
      reference = sp.reference;
      reference->addRef();
    }

    return *this;
  }
};

int main(){
  Smartpointer<string> sp;
  Smartpointer<string> sp2;
  sp = sp2;
  return 0;
}
