#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x, y;

	public:
		// Constructores
		vect2();
		vect2(int a, int b);
		vect2(const vect2& v);

		// Destructor
		~vect2();

		// Asignación y acceso
		vect2& operator=(const vect2& v);
		int operator[](int i) const;
		int& operator[](int i);

		// Operadores unarios
		vect2 operator-() const;

		// Multiplicación por escalar
		vect2 operator*(int n) const;
		vect2& operator*=(int n);

		// Operadores con vectores
		vect2& operator+=(const vect2& v);
		vect2& operator-=(const vect2& v);
		vect2& operator*=(const vect2& v);
		vect2 operator+(const vect2& v) const;
		vect2 operator-(const vect2& v) const;
		vect2 operator*(const vect2& v) const;

		// Incremento y decremento
		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		// Comparaciones
		bool operator==(const vect2& v) const;
		bool operator!=(const vect2& v) const;
};

// Funciones amigas
vect2 operator*(int n, const vect2& v);
std::ostream& operator<<(std::ostream& os, const vect2& v);

#endif

