#include "iter.hpp"

template<typename T>
void	add(T &t)
{
	srand(time(NULL));
  int e = rand() % 5;
  
  t += e;
}

template<typename T>
void	subtract(T &t)
{
	srand(time(NULL));
  int e = rand() % 5;

  t -= e;
}

template<typename T>
void	mult(T &t)
{
	srand(time(NULL));
  int e = rand() % 5;

  t *= e;
}

template<typename T>
void	div(T &t)
{
	srand(time(NULL));
  int e = rand() % 5 + 1;

  t /= e;
}


template<typename T>
void print(T const &x)
{
  std::cout << x << std::endl;
}

int main()
{
  {
    std::cout << "-----INT-----" << std::endl;
    int tab[] = {0, 1, 2, 3, 4};
    std::cout << "SUMAR" << std::endl;
    iter(tab, 5, add<int>);
    iter(tab, 5, print<int>);
    std::cout << "RESTAR" << std::endl;
    iter(tab, 5, subtract<int>);
    iter(tab, 5, print<int>);
    std::cout << "MULTIPLICAR" << std::endl;
    iter(tab, 5, mult<int>);
    iter(tab, 5, print<int>);
    std::cout << "DIVIDIR" << std::endl;
    iter(tab, 5, div<int>);
    iter(tab, 5, print<int>);
  }
  {
    std::cout << "-----FLOAT-----" << std::endl;
    float tab[] = {0, 1.2f, 2.4f, 3.6f, 4.8f};
    std::cout << "SUMAR" << std::endl;
    iter(tab, 5, add<float>);
    iter(tab, 5, print<float>);
    std::cout << "RESTAR" << std::endl;
    iter(tab, 5, subtract<float>);
    iter(tab, 5, print<float>);
    std::cout << "MULTIPLICAR" << std::endl;
    iter(tab, 5, mult<float>);
    iter(tab, 5, print<float>);
    std::cout << "DIVIDIR" << std::endl;
    iter(tab, 5, div<float>);
    iter(tab, 5, print<float>);
  }
  {
    std::cout << "-----DOUBLE-----" << std::endl;
    double tab[] = {0, 1.2, 2.4, 3.6, 4.8};
    
    std::cout << "SUMAR" << std::endl;
    iter(tab, 5, add<double>);
    iter(tab, 5, print<double>);
    std::cout << "RESTAR" << std::endl;
    iter(tab, 5, subtract<double>);
    iter(tab, 5, print<double>);
    std::cout << "MULTIPLICAR" << std::endl;
    iter(tab, 5, mult<double>);
    iter(tab, 5, print<double>);
    std::cout << "DIVIDIR" << std::endl;
    iter(tab, 5, div<double>);
    iter(tab, 5, print<double>);
  }
  return (0);
}