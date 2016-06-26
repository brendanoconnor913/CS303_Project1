#include"Ordered_list.h"

class Term{
private:
	int coefficient;
	int exponent;

	Term* next;
	Term* prev;

	Term (const int& givenCoefficient, const int& givenExponent, 
		Term* prevValue = NULL, Term* nextValue =NULL) :
				coefficient(givenCoefficient), exponent(givenExponent), prev(prevValue), next(nextValue){}
public:
	int getExponent(){
		return exponent;
	}

	int getCoefficient(){
		return coefficient;
	}

	bool operator>(Term& rhs){
		return exponent>rhs.getExponent();
	}

	bool operator<(Term& rhs){
		return exponent<rhs.getExponent();
	}

	Term* operator+(Term& rhs){
		if (exponent==rhs.getExponent()){
			Term* sum = new Term((coefficient+rhs.getCoefficient()), rhs.getExponent(), prev, next);
			return sum;
		}
		else 
			throw std::invalid_argument("not like terms");
		
	}
};