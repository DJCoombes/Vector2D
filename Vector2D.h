#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

template<class G>

class Vector2D
{
protected:
	G m_x;
	G m_y;
public:
	Vector2D() : m_x(G(0)), m_y(G(0)) {}
	Vector2D(const G& allValues) { m_x = allValues; m_y = allValues; }
	Vector2D(const G& X, const G& Y) { m_x = X; m_y = Y; }

	void setX(const G& X) { m_x = X; }
	void setY(const G& Y) { m_y = Y; }
	void set(const G& X, const G& Y) { m_x = X; m_y = Y; }
	void set(const Vector2D& v) { m_x = v.m_x; m_y = v.m_y; }

	G x() const { return m_x; }
	G y() const { return m_y; }

	Vector2D operator+(const Vector2D& v) const { return Vector2D(m_x + v.m_x, m_y + v.m_y); }
	Vector2D operator-(const Vector2D& v) const { return Vector2D(m_x - v.m_x, m_y - v.m_y); }
	Vector2D operator*(const Vector2D& v) const { return Vector2D(m_x * v.m_x, m_y * v.m_y); }
	Vector2D operator/(const Vector2D& v) const { return Vector2D(m_x / v.m_x, m_y / v.m_y); }

	void operator=(const Vector2D& v) { m_x = v.m_x; m_y = v.m_y; }

	bool operator==(const Vector2D& v) const { return ((m_x == v.m_x) && (m_y == v.m_y)); }
	bool operator!=(const Vector2D& v) const { return !((m_x == v.m_x) && (m_y == v.m_y)); }

	// Negate both the x and y values.
	Vector2D operator-() const { return Vector2D(-m_x, -m_y); }

	// Scale both the x and y values.
	Vector2D operator*(const G& scalar) const { return Vector2D(m_x * scalar, m_y * scalar); }
	Vector2D operator/(const G& scalar) const { return Vector2D(m_x / scalar, m_y / scalar); }

	G dotProduct(const Vector2D& v) const { return ((m_x * v.m_x) + (m_y * v.m_y)); }
	G crossProduct(const Vector2D& v) const { return ((m_x * v.m_y) - (m_y * v.m_x)); }
	G magnitude() const { return sqrt(m_x * m_x + m_y * m_y); }

	Vector2D normal() const { return Vector2D(m_x / magnitude(), m_y / magnitude()); }
	Vector2D perpendicular() const { return Vector2D(m_y, -m_x); }
};

#endif
