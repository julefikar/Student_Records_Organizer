#include "Polynomial.h"

Polynomial::Polynomial()
{
	coefficients = std::vector<int>();
}
Polynomial::Polynomial(std::vector<int> value)
{
	coefficients.clear();
	for (int i = 0; i < value.size(); i++)
		coefficients.push_back(value.at(i));
}
void Polynomial::Set(std::vector<int> value)
{
	coefficients.clear();
	for (int i = 0; i < value.size(); i++)
		coefficients.push_back(value.at(i));
}

std::ostream& operator<<(std::ostream& output, const Polynomial& ploy)
{
	if(ploy.coefficients.size() == 0)
	{
		output << "Empty";
	}
	else
	{
		int j = ploy.coefficients.size() - 1;
		for (int i = 0; i < ploy.coefficients.size(); i++)
		{
			if (ploy.coefficients.at(i) < 0)
			{
				output << "- ";
				if (j == 0)
				{
					output << abs(ploy.coefficients.at(i));
				}
				else
				{
					if (ploy.coefficients.at(i) != -1)
						output << abs(ploy.coefficients.at(i)) << "*";
					output << "x";
					if (j > 1)
						output << "^" << j << " ";
					else
						output << " ";
				}

			}
			else if (ploy.coefficients.at(i) > 0)
			{
				if (i != 0)
					output << "+ ";
				if (j == 0)
				{
					output << ploy.coefficients.at(i);
				}
				else
				{
					if (ploy.coefficients.at(i) != 1)
						output << ploy.coefficients.at(i) << "*";
					output << "x";
					if (j > 1)
						output << "^" << j << " ";
					else
						output << " ";
				}
			}
			j--;
		}
	}
	return output;
}

float Polynomial::operator()(float var)
{
	int j = this->coefficients.size() - 1;
	float value = 0;
	for (int i = 0; i < this->coefficients.size(); i++)
	{
		if (this->coefficients.at(i) != 0)
		{
			if(j == 0)
				value += this->coefficients.at(i);
			else
				value += this->coefficients.at(i) * (pow(var, j));
		}
		j--;
	}
	return value;
}



Polynomial operator + (Polynomial const& poly1, Polynomial const& poly2)
{
	std::vector<int> result;
	int i = 0, j = 0;
	int size1 = poly1.coefficients.size() - 1;
	int size2 = poly2.coefficients.size() - 1;

	if (size1 == -1)
	{
		for (j = 0; j <= size2; j++)
			result.push_back(poly2.coefficients.at(j));
	}
	else if (size2 == -1)
	{
		for (i = 0; i <= size1; i++)
			result.push_back(poly1.coefficients.at(i));
	}
	else
	{
		while (true)
		{
			if (size1 == -1 && size2 == -1)
				break;
			if (size1 == size2)
			{
				result.push_back(poly1.coefficients.at(i) + poly2.coefficients.at(j));
				size1--; size2--;
				if (i != poly1.coefficients.size() - 1)
					i++;
				if (j != poly2.coefficients.size() - 1)
					j++;
			}
			else if (size1 > size2)
			{
				result.push_back(poly1.coefficients.at(i));
				if (i != poly1.coefficients.size() - 1)
					i++;
				size1--;
			}
			else if (size2 > size1)
			{
				result.push_back(poly2.coefficients.at(j));
				if (j != poly2.coefficients.size() - 1)
					j++;
				size2--;
			}
		}
	}

	Polynomial r{ result };
	return r;
}

Polynomial operator - (Polynomial const& poly1, Polynomial const& poly2)
{
	std::vector<int> result;
	int i = 0, j = 0;
	int size1 = poly1.coefficients.size() - 1;
	int size2 = poly2.coefficients.size() - 1;

	if (size1 == -1)
	{
		for (j = 0; j <= size2; j++)
			result.push_back(poly2.coefficients.at(j) * -1);
	}
	else if (size2 == -1)
	{
		for (i = 0; i <= size1; i++)
			result.push_back(poly1.coefficients.at(i));
	}
	else
	{
		j = 0;
		while (true)
		{
			if (size1 == -1 && size2 == -1)
				break;
			if (size1 == size2)
			{
				result.push_back(poly1.coefficients.at(i) + (poly2.coefficients.at(j) * -1));
				size1--; size2--;
				if (i != poly1.coefficients.size() - 1)
					i++;
				if (j != poly2.coefficients.size() - 1)
					j++;
			}
			else if (size1 > size2)
			{
				result.push_back(poly1.coefficients.at(i));
				if (i != poly1.coefficients.size() - 1)
					i++;
				size1--;
			}
			else if (size2 > size1)
			{
				result.push_back(poly2.coefficients.at(j) * -1);
				if (j != poly2.coefficients.size() - 1)
					j++;
				size2--;
			}
		}
	}

	Polynomial r{ result };
	return r;
}

Polynomial operator * (Polynomial const& poly1, Polynomial const& poly2)
{
	std::vector<int> result;
	Polynomial r;
	int i = 0, j = 0;
	int size1 = poly1.coefficients.size() - 1;
	int size2 = poly2.coefficients.size() - 1;

	if (size1 == -1 || size2 == -1)
	{}
	else
	{
		std::vector<int> temp;
		for (i = 0; i < poly1.coefficients.size(); i++)
		{
			int k = size1 + size2 + 1;
			if (poly1.coefficients.at(i) != 0)
			{
				for (j = 0; j < poly2.coefficients.size(); j++)
				{
					if (i == 0)
						result.push_back(poly1.coefficients.at(i) * poly2.coefficients.at(j));
					else
						temp.push_back(poly1.coefficients.at(i) * poly2.coefficients.at(j));
				}
				if (i == 0)
				{
					int m = result.size();
					for (int l = 0; l < (k - m); l++)
						result.push_back(0);
				}
				else
				{
					int m = temp.size();
					for (int l = 0; l < (k - m); l++)
						temp.push_back(0);
				}
				size1--;
				if (result.size() != 0 && temp.size() != 0)
				{
					Polynomial a{ result };
					Polynomial b{ temp };

					r = a + b;
					result.clear();
					temp.clear();
					for (int count = 0; count < r.coefficients.size(); count++)
					{
						result.push_back(r.coefficients.at(count));
					}
				}
			}
			else
				size1--;
		}
	}
	return r;
}