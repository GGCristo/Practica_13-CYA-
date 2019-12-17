#include <iostream>
#include <stack>
#include <vector>
#include <utility> // pair
#include <cmath>

void monedas_constructor(std::stack<float>&, bool billetes = 1);   
std::vector<std::pair<float, int>> algoritmo_voraz(float, std::stack<float>);
std::ostream& operator << (std::ostream&, std::vector<std::pair<float,int>>);

int main () {
  std::stack<float> monedas;
  monedas_constructor(monedas);
  float cantidad;
  std::cout << "Introduce la cantidad\n";
  std::cin >> cantidad;
  std::cout << algoritmo_voraz(cantidad, monedas);
  return 0;
}

std::vector<std::pair<float,int>> algoritmo_voraz(float restante, std::stack<float> monedas)
{
  std::vector<std::pair<float,int>> cambio;
  while (restante != 0)
  { 
    if (restante < 0.01)
    {
      restante = 0; 
    }
    else if (restante > monedas.top())      
    { 
      if (!cambio.empty() && fabs(std::get<0>(cambio.back()) - monedas.top()) < 1e-8)
      {
        std::get<1>(cambio.back())++;
        restante -= monedas.top();
      } 
      else
      {
        cambio.push_back(std::make_pair(monedas.top(),1));
        restante -= monedas.top();
      }
    }
    else if (fabs(restante - monedas.top()) < 0.001) 
    {
      cambio.push_back(std::make_pair(monedas.top(),1));
      restante = 0;
    }
    else  


      monedas.pop();
    
  }
  return cambio;
}

void monedas_constructor (std::stack<float> &monedas, bool billetes) 
{
  monedas.push(0.01);
  monedas.push(0.02);
  monedas.push(0.05);
  monedas.push(0.1);
  monedas.push(0.2); 
  monedas.push(0.5);
  monedas.push(1);
  monedas.push(2);
  if (billetes) 
  {
    monedas.push(5);
    monedas.push(10);
    monedas.push(20);
    monedas.push(50);
    monedas.push(100);
    monedas.push(200);
    monedas.push(500);
  }
}

std::ostream& operator << (std::ostream& os, std::vector<std::pair<float,int>> vector)
{
  for (float i = 0; i < vector.size(); i++)
  {
    if (std::get<0>(vector[i]) >= 1)
      os << std::get<1>(vector[i]) << "x" << std::get<0>(vector[i]) << "$ ";
    else 
      os << std::get<1>(vector[i]) << "x" << std::get<0>(vector[i])*100 << "c ";
  }
  os << "\n";
  return os;
}

