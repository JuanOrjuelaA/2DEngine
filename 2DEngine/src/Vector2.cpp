#include "../include/Vector2.h"

#include<cmath>

using namespace WitzEngine;

float Vector2::length() const
{
	return sqrtf((m_x * m_x) + (m_y * m_y));
}

Vector2 Vector2::operator+ (const Vector2& vector2) const
{
	return {m_x + vector2.m_x, m_y + vector2.m_y};
}


Vector2 Vector2::operator*(float scalar) const
{
	return {m_x * scalar, m_y * scalar};
}

Vector2& Vector2::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	return *this;
}

Vector2 Vector2::operator-(const Vector2& vector2) const
{
	return {m_x - vector2.m_x, m_y - vector2.m_y};
}


Vector2 Vector2::operator/(float scalar) const
{
	return {m_x / scalar, m_y / scalar};
}

Vector2& Vector2::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;

	return *this;
}

void Vector2::normalize()
{
	const auto l = length();
	if(l > 0)
	{
		(*this) *= 1 / l;
	}
}


