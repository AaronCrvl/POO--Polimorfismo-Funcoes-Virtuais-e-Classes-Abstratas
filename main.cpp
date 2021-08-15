#include <iostream>
#include <vector>
#include "Universidade.h"
#include "Funcao.h"
using namespace std;

int main(){
  Universidade u;
  u.addProfessor("Prof_1", 1000);
  u.addProfessor("Prof_2", 8, 150);
  u.addProfessor("Prof_3", 6, 250);
  u.addProfessor("Prof_4", 4, 700);

  cout << endl << "Valor total pago aos professores: R$ " << u.totalPago() << endl << endl;

  double resultado;

  //cria um container de ponteiros do tipo Funcao
  Funcao *f[3];

  f[0] = new Quadratica(1,2,4);
  f[1] = new Senoide();
  f[2] = new Linear(1,4);

  cout << "*** Calculo de integrais usando a regra do trapezio: ***"<<endl<<endl;
  cout << "*** Funcoes ***" << endl;
  cout << "(1) x^2 + 2x + 4" << endl;
  cout << "(2) sen(x) / x" << endl;
  cout << "(3) x + 4" << endl;
  cout << endl;

  for (int i=0; i<3; i++)
  {
    resultado = f[i]->getIntegral(1,4,1000);
    cout << "Integral da Funcao (" << i+1 << "): " << resultado << endl;
  }

  for (int i=0; i<3; i++)
  {
    delete f[i];
  }

  return 0;
}
// !_MAIN