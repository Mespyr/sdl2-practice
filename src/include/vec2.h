#pragma once

template <typename T>
class Vec2 {
public:
	Vec2() {}
	Vec2(T x, T y)
		: x(x), y(y)
	{}

	Vec2 operator+(const Vec2 &v) {
		return Vec2(x + v.x, y + v.y);
	}

	void operator+=(const Vec2 &v) {
		x += v.x;
		y += v.y;
	}

	Vec2 operator*(const Vec2 &v) {
		return Vec2(x * v.x, y * v.y);
	}

	Vec2 operator*(const T &v) {
		return Vec2(x * v, y * v);
	}

	T x, y;
};
