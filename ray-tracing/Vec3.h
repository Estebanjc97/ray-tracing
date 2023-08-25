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