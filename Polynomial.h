#ifndef Polynomial_h
#define Polynomial_h

#include <vector>
#include <iostream>
#include <string>

class Polynomial
{
private:
	std::vector<int> coefficients;
	std::string ploynomial;
public:
	Polynomial();
	Polynomial(std::vector<int> value);
	void Set(std::vector<int> value);
	float operator()(float);
	friend std::ostream& operator<<(std::ostream& output, const Polynomial& ploy);
	friend Polynomial operator + (Polynomial const&, Polynomial const&);
	friend Polynomial operator - (Polynomial const&, Polynomial const&);
	friend Polynomial operator * (Polynomial const&, Polynomial const&);
};
#endif