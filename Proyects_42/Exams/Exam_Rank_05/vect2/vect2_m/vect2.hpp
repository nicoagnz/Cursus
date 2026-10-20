#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x, y;

	public:
		// Constructores
		vect2() : x(0), y(0) {}
		vect2(int a, int b) : x(a), y(b) {}
		vect2(const vect2& v) : x(v.x), y(v.y) {}

		// Destructor
		~vect2() {}

		// Asignación y acceso
		vect2& operator=(const vect2& v)
		{
			x = v.x;
			y = v.y;
			return *this;
		}

		int operator[](int i) const
		{
			return i == 0 ? x : y;
		}

		int& operator[](int i)
		{
			return i == 0 ? x : y;
		}

		// Operadores unarios
		vect2 operator-() const
		{
			return vect2(-x, -y);
		}

		// Multiplicación por escalar
		vect2 operator*(int n) const
		{
			return vect2(x * n, y * n);
		}

		vect2& operator*=(int n)
		{
			x *= n;
			y *= n;
			return *this;
		}

		// Operadores con vectores
		vect2& operator+=(const vect2& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		vect2& operator-=(const vect2& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		vect2& operator*=(const vect2& v)
		{
			x *= v.x;
			y *= v.y;
			return *this;
		}

		vect2 operator+(const vect2& v) const
		{
			vect2 t(*this);
			return t += v;
		}

		vect2 operator-(const vect2& v) const
		{
			vect2 t(*this);
			return t -= v;
		}

		vect2 operator*(const vect2& v) const
		{
			vect2 t(*this);
			return t *= v;
		}

		// Incremento y decremento
		vect2& operator++()
		{
			++x;
			++y;
			return *this;
		}

		vect2 operator++(int)
		{
			vect2 t(*this);
			++(*this);
			return t;
		}

		vect2& operator--()
		{
			--x;
			--y;
			return *this;
		}

		vect2 operator--(int)
		{
			vect2 t(*this);
			--(*this);
			return t;
		}

		// Comparaciones
		bool operator==(const vect2& v) const
		{
			return x == v.x && y == v.y;
		}

		bool operator!=(const vect2& v) const
		{
			return !(*this == v);
		}
};

// Funciones libres marcadas como inline
inline vect2 operator*(int n, const vect2& v)
{
	return v * n;
}

inline std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	return os << "{" << v[0] << ", " << v[1] << "}";
}

#endif