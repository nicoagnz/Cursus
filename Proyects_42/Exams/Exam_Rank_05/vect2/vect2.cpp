
#include "vect2.hpp"

// Constructores
vect2::vect2() : x(0), y(0) {}
vect2::vect2(int a, int b) : x(a), y(b) {}
vect2::vect2(const vect2& v) : x(v.x), y(v.y) {}

// Destructor
vect2::~vect2() {}

// Asignación y acceso
// v1 = v2
vect2& vect2::operator=(const vect2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

// Acceso a los componentes del vector
// v[0] devuelve x
// v[1] devuelve y
// Para objetos const
int vect2::operator[](int i) const
{
	return i == 0 ? x : y;
}

// Acceso a los componentes del vector
// v[0] devuelve x
// v[1] devuelve y
int& vect2::operator[](int i)
{
	return i == 0 ? x : y;
}

// Operadores unarios
// cambia el simbolo de los componentes del vector
// v1(1, -2)
// -v1 == v1(-1, 2) 
vect2 vect2::operator-() const
{
	return vect2(-x, -y);
}

// Multiplicación por escalar
// v1 * n
vect2 vect2::operator*(int n) const
{
	return vect2(x * n, y * n);
}

// v1 *= n
vect2& vect2::operator*=(int n)
{
	x *= n;
	y *= n;
	return *this;
}

// Operadores con vectores
// v1 += v2
vect2& vect2::operator+=(const vect2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

// v1 -= v2
vect2& vect2::operator-=(const vect2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

// v1 *= v2
vect2& vect2::operator*=(const vect2& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

// v1 + v2
vect2 vect2::operator+(const vect2& v) const
{
	vect2 t(*this);
	return t += v;
}

// v1 - v2
vect2 vect2::operator-(const vect2& v) const
{
	vect2 t(*this);
	return t -= v;
}

// v1 * v2
vect2 vect2::operator*(const vect2& v) const
{
	vect2 t(*this);
	return t *= v;
}

// Incremento y decremento
// ++v
vect2& vect2::operator++()
{
	++x;
	++y;
	return *this;
}

// v++
vect2 vect2::operator++(int)
{
	vect2 t(*this);
	++(*this);
	return t;
}

// --v
vect2& vect2::operator--()
{
	--x;
	--y;
	return *this;
}

// v--
vect2 vect2::operator--(int)
{
	vect2 t(*this);
	--(*this);
	return t;
}

// Comparaciones
bool vect2::operator==(const vect2& v) const
{
	return x == v.x && y == v.y;
}

bool vect2::operator!=(const vect2& v) const
{
	return !(*this == v);
}

// Funciones amigas
// n * v
vect2 operator*(int n, const vect2& v)
{
	return v * n;
}

// para imprimir numero en pantalla
// std::cout << v << std::endl
std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	return os << "{" << v[0] << ", " << v[1] << "}";
}

