//
// Created by msumi on 28/06/2023.
//

#ifndef REVOLUTION_GAME_VECTOR2D_H
#define REVOLUTION_GAME_VECTOR2D_H
#include <cmath>

template <typename T>
class Vector2d {
public:
    T x;
    T y;

    Vector2d();
    Vector2d(T x_, T y_);
    void operator=(const Vector2d<T>& other);
    Vector2d<T> operator-(const Vector2d<T>& other) const;
    Vector2d<T> operator+(const Vector2d<T>& other) const;
    Vector2d<T> operator*(T scalar) const;
    Vector2d<T> operator/(T scalar) const;
    float modulo() const;
    Vector2d<float> vUnitario();
    T getX() const;
    void setX(T x);
    T getY() const;
    void setY(T y);
    void setXY(T x,T y);
};
template <typename T>
Vector2d<T>::Vector2d(){x = 0; y = 0;}
template <typename T>
Vector2d<T>::Vector2d(T x_, T y_) : x(x_), y(y_) {}
template <typename T>
void Vector2d<T>::operator=(const Vector2d<T>& other) {
    this->x = other.x;
    this->y = other.y;
}
template <typename T>
Vector2d<T> Vector2d<T>::operator-(const Vector2d<T>& other) const {
    return Vector2d(x - other.x, y - other.y);
}
template <typename T>
Vector2d<T> Vector2d<T>::operator+(const Vector2d& other) const {
    return Vector2d(x + other.x, y + other.y);
}
template <typename T>
Vector2d<T> Vector2d<T>::operator*(T scalar) const {
    return Vector2d<T>(x * scalar, y * scalar);
}
template <typename T>
Vector2d<T> Vector2d<T>::operator/(T scalar) const {
    assert(scalar != 0);
    return Vector2d<T>(x / scalar, y / scalar);
}
template <typename T>
float Vector2d<T>::modulo() const {
    return std::sqrt(x * x + y * y);
}
template <typename T>
Vector2d<float> Vector2d<T>::vUnitario() {
    return *this / modulo();
}
template <typename T>
T Vector2d<T>::getX() const {
    return x;
}
template <typename T>
void Vector2d<T>::setX(T x) {
    this->x = x;
}
template <typename T>
T Vector2d<T>::getY() const {
    return y;
}
template <typename T>
void Vector2d<T>::setY(T y) {
    this->y = y;
}
template <typename T>
void Vector2d<T>::setXY(T x,T y){
    this->x = x;
    this->y = y;
}
#endif //REVOLUTION_GAME_VECTOR2D_H
