#ifndef UNIVERSIDADE
#define UNIVERSIDADE
#include <iostream>
#include <vector>
using namespace std;

class Professor
{
  private:
    string nome;

  public:
    Professor() { this->setNome(""); };
    Professor(string n){ this->setNome(n); };
    
    string getName() const;
    void setNome(string nm) { this->nome = nm; };

    virtual double getSalario(){ return 0.0; };
    
    //virtual ~Professor();
};

class ProfHorista: public Professor
{
  private:  
    double nrNorasTrabalhadas;
    double valorHora;

  public:
    ProfHorista(string n, double nht, double vh)
    {
      this->setNome(n);
      this->nrNorasTrabalhadas = nht;
      this->valorHora = vh;
    }
    double getSalario() override { return this->valorHora * this->nrNorasTrabalhadas; };
    //virtual ~ProfHorista();
};

class ProfIntegral: public Professor {
  private:
    double salarioMensal;
  public:
    ProfIntegral(string n, double sm)
    {
      this->setNome(n);
      this->salarioMensal = sm;
    }
    double getSalario() override { return this->salarioMensal; };
    //virtual ~ProfIntegral(){}
};

class Universidade
{
  private:
   vector<Professor*>prof;

  public:
    void addProfessor(string nome, double salarioMensal)
    {
      prof.push_back(new ProfIntegral (nome, salarioMensal));
    }

    void addProfessor(string nome, double nrNorasTrabalhadas, double valorHora)
    {
      prof.push_back(new ProfHorista (nome, nrNorasTrabalhadas, valorHora));
    }    

    double totalPago()
    { 
      double total = 0;
      for(int i=0; i<prof.size(); i++)
      {
        total = prof[i]->getSalario() + total;
      }
      return total;
    }
};
#endif
// !_UNIVERSIDADE !_PROFESSOR