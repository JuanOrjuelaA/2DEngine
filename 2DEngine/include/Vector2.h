#ifndef WITZ_ENGINE_VECTOR_2_H
#define WITZ_ENGINE_VECTOR_2_H

namespace WitzEngine
{
	class Vector2
	{
	public:
		Vector2(float x, float y) : m_x(x), m_y(y) {}

		float getX() const { return m_x; }
		float getY() const { return m_y; }

		void setX(float x) { m_x = x; }
		void setY(float y) { m_y = y; }

		float length() const;

		Vector2 operator+(const Vector2& vector2) const;
		friend Vector2& operator+=(Vector2& v1, const Vector2& v2);

		Vector2 operator*(float scalar) const;
		Vector2& operator*=(float scalar);

		Vector2 operator-(const Vector2& vector2) const;
		friend Vector2& operator-=(Vector2& v1, const Vector2& v2);

		Vector2 operator/(float scalar) const;
		Vector2& operator/=(float scalar);

		void normalize();

	private:
		float m_x;
		float m_y;
	};
}

#endif
