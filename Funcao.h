#ifndef FUNCAO
#define FUNCAO
#include <iostream>
#include <cmath>
using namespace std;

class Funcao
{
  public:

    virtual double getIntegral(double limiteInferior, double limiteSuperior, double intervalos)
    {
      //Função modificada para virtual pois a chamada da função é por classe.
      return 0.0;
    };

    // funcao virtual representando a funcao cuja integral deve ser calculada
    virtual double func(double input){ return 0.0; };

    // destrutor
    //virtual ~Funcao(){}
};

class Quadratica: public Funcao
{
  private:
    double var_a, var_b, var_c;
  
  public:
    Quadratica(double _a = 0.0, double _b = 0.0, double _c = 0.0)
    {  
      this->var_a = _a;
      this->var_b = _b;
      this->var_c = _c;
    };

    double func (double input) override
    { 
      double func = this->var_a*(pow(2,input)) + (this->var_b*input) + this->var_c;
      return func;
    };

    //!_EXTRA
    /*double calc_tx_Erro(double intervalos)
    {
      double dist = 1;
      double tx_erro = (intervalos*(pow(3,dist)))/12 * 2;
      cout << endl << "TX_ERRO: " << tx_erro << endl;
      return tx_erro;
    };*/

    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos) override
    {
      double res = ( ( (func(limiteSuperior)+func(limiteInferior)) * (limiteSuperior - limiteInferior) ) )/2;
      //res -= calc_Erro(intervalos);
      return res;
    };
};

class Linear: public Funcao
{
  private:
    double var_a, var_b;
  
  public:
    Linear(double _a = 0.0, double _b = 0.0)
    {
      this->var_a = _a;
      this->var_b = _b;
    };

    double func (double input) override
    { 
      double func = (this->var_a*input) + this->var_b;
      return func;
    };

    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos) override
    {
      double res = ( ( (func(limiteSuperior)+func(limiteInferior)) * (limiteSuperior - limiteInferior) ) )/2;
      return res;
    };
};

class Senoide: public Funcao
{
  public:
    Senoide(){};

    double func (double input) override
    { 
      double func = (sin(input))/input; 
      return func;
    };

    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos) override
    {
      double res = ( ( (func(limiteSuperior)+func(limiteInferior)) * (limiteSuperior - limiteInferior) ) )/2;
      return res;
    };
};

#endif
// !_FUNCAO