#include<iostream>
#include<complex>
#include<conio.h>
#include <cctype>

using namespace std;
template <typename T>
class Complex {
	std::complex< double >number;
public:
	Complex() {
		number = 0;
	}
	Complex(const Complex&c) {
		this->number = c.number;
	}
	
	void print(ostream&) {

		cout << "\nComplex number: " << real(number)<<" + "<<imag(number)<<"i";
	}
	void set(istream&) {
		double x, y;
		cin >> x;
		real(number) = x;
		cin >> y;
		imag(number) = y;
	}

	void add(std::complex< double >x, std::complex< double >y) {
		number = x + y;
		cout << "\nProceeding with summ...";
		cout << "\n" << conj(x) << " + " << conj(y) << " = " << conj(number)<<endl;
	}
	void sub(std::complex< double >x, std::complex< double >y) {
		number = x-y;
		cout << "\nProceeding with substraction...";
		cout << "\n" << conj(x) << " - " << conj(y) << " = " << conj(number)<<endl;
	}
	template <typename T>
	void mult(std::complex< double >x,T y) {
		std::complex< double >buf(double(y), 0.0);
		number = x * buf;
		cout << "\nProceeding with multiplication...";
		cout << "\n" << conj(x) << " * " << y << " = " << conj(number) << endl;
	}
	template<typename T>
	void div(std::complex< double >x, T y) {
		try {
			if (y != 0) {
				std::complex< double >buf(double(y), 0.0);
				this->number = x / buf;
				cout << "\nProceeding with division...";
				cout << "\n" << conj(x) << " / " << y << " = " << conj(number) << endl;
			}
			else throw "Can't divide by zero!";
		}
		catch (char *err) {
			cout << "\nProceeding with division...";
			cout << "\n" << conj(x) << " / " << 0;
			cout << "\nError:" << err;
			cout << "\nChange another number...";
				char str[64];
				cin >> str;
				int new_num;
				if (isdigit(str[0])) {
					new_num = atoi(str);
					cout << new_num;
				}
				div(x, new_num);
			}
		}
	
	friend ostream & operator <<(ostream&, const Complex<T>& );
	friend istream& operator >> (istream&, Complex<T>&);

	Complex operator +(const Complex& c) {
		Complex buf(*this);
		buf.number += c.number;
		return buf;
	}
	Complex operator -(const Complex& c) {
		Complex buf(*this);
		buf.number -= c.number;
		return buf;
	}
	Complex operator *(const Complex& c) {
		Complex buf(*this);
		buf.number *= c.number;
		return buf;
	}
	Complex operator /(const Complex& c) {
		Complex buf(*this);
		buf.number /= c.number;
		return buf;
	}
	Complex operator +=(const Complex& c) {
		number += c.number;
		return *this;
	}
	Complex operator -=(const Complex& c) {
		number -= c.number;
		return *this;
	}
	Complex operator *=(const Complex& c) {
		number *= c.number;
		return *this;
	}
	Complex operator /=(const Complex& c) {
		number /= c.number;
		return *this;
	}
	Complex operator =(const Complex& c) {
		number = c.number;
		return *this;
	}
	bool operator ==(const Complex& c) {
		if(this->number==c.number)
		return true;
		else return false;
	}
	
};
template<typename T>
ostream & operator <<(ostream& out, const Complex<T>& d) {
	d.print(out);
	return out;
}
template<typename T>
istream & operator >>(istream& in, const Complex<T>& d) {
	d.set(in);
	return in;
}




 




int main() {
	std::complex< double >x(1.0, 3.0);
	std::complex< double >y(4.0, 2.0);
	Complex <double>C, D,E;
	C.add(x,y);
	D.mult(x,4);
	if (E == C) cout << "\nYou picked the wrong house,fool!!";
	_getch();
	return 0;
}
