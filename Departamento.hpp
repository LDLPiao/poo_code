#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

using namespace std;

class Departa : public Animal {
  
  int age;
protected:
  string nome;
public:
  Ave (int , const string&);
  ~Ave();
  void voa();
  void botaOvo();  
  //void dorme();
  friend class Ave2;
  int getAge();
  
};


#endif 
