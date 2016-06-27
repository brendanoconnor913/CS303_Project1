#include"Ordered_list.h"

class Term{
private:
	int coefficient;
	int exponent;
	
public:
	friend bool operator<(const Term& lhs, const Term& rhs);
	
	Term(const int& givenCoefficient, const int& givenExponent) :
		coefficient(givenCoefficient), exponent(givenExponent) {}

	Term() {
		coefficient = 0;
		exponent = 0;
	}

	int getExponent(){
		return exponent;
	}

	int getCoefficient(){
		return coefficient;
	}

	const int getExponent (int) const {
		return exponent;
	} 

	const int getCoefficient (int) const {
		return coefficient;
	}

	bool operator>(Term rhs){
		return exponent > rhs.getExponent();
	}

	bool operator<(Term rhs){
		return exponent < rhs.getExponent();
	}

	Term& operator+(Term rhs){
		if (exponent==rhs.getExponent()){
			Term sum((coefficient + rhs.getCoefficient()), rhs.getExponent());
			return sum;
		}
		else 
			throw std::invalid_argument("not like terms");
		
	}

	bool operator==(Term& rhs) {
		return exponent == rhs.exponent;
			
	}

	bool operator!=(Term& rhs) {
		return exponent != rhs.exponent;
	}
	
};
