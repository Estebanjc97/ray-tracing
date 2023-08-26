#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    double e[3];

    vec3() : e{ 0,0,0 } {} // Constructor por defecto, inicializa el vector como (0, 0, 0).
    vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {} // Constructor con valores iniciales.

    // Funciones para acceder a las componentes individuales del vector.
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // Sobrecarga del operador negativo para obtener el vector opuesto.
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // Sobrecarga del operador de indexación para acceder a las componentes del vector.
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    // Sobrecarga de operadores para realizar operaciones de modificación en el vector.
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(double t) {
        return *this *= 1 / t;
    }

    // Calcula la longitud (magnitud) del vector.
    double length() const {
        return sqrt(length_squared());
    }

    // Calcula la longitud al cuadrado del vector (optimización para evitar la raíz cuadrada).
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// point3 es simplemente un alias para vec3, útil para claridad geométrica en el código.
using point3 = vec3;

// Funciones de utilidad para operar con vectores.

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Sobrecarga de operadores para realizar operaciones matemáticas con vectores.
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}

// Producto punto entre dos vectores.
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

// Producto cruz entre dos vectores.
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Retorna un vector unitario en la misma dirección que el vector dado.
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}