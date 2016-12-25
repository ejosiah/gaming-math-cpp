//
//  vector.h
//  maths
//
//  Created by Josiah Ebhomenye on 24/12/2016.
//  Copyright © 2016 Josiah Ebhomenye. All rights reserved.
//

#ifndef vector_h
#define vector_h

#include <initializer_list>
#include <iostream>

#include "precision.h"

namespace ncl {
    class Vector{
    public:
        union{
            struct { real x, y, z, w; };
            struct { real r, g, b, a; };
            real data[4];
        };
        
    public:
        Vector(real x = 0, real y = 0, real z = 0, real w = 0);
        
        Vector(std::initializer_list<real> v);
        
        real squreLength() const;
        
        real length() const;
        
        real  operator()() const;
        
        Vector& operator+=(const Vector& v);
        
        Vector operator+(const Vector& v) const;
        
        Vector& operator-=(const Vector& v);
        
        
        Vector operator-(const Vector& v) const;
        
        Vector compProduct(const Vector& v) const;
        
        Vector& operator*=(real s);
        
        Vector operator*(const real s) const;
        
        Vector& addScaled(const Vector& v, real s);
        
        bool operator==(const Vector& v) const;
        
        bool operator<=(const Vector& v) const;
        
        Vector& normalize();
        
        
        real operator[](const char key) const;
        
        real& operator[](const char key);
        
        real operator[](const unsigned i) const;
        
        real& operator[](const unsigned i);
        
        
        real dot(const Vector& v) const;
        
        Vector cross(const Vector& v) const;
        
        Vector& crossProductUpdate(const Vector& v);
        
        real operator%(const Vector& v) const;
        
        Vector operator*(const Vector& v) const;
        
        Vector& operator*=(const Vector& v);
        
        Vector& invert();
        
        
        Vector& operator-();
        
        operator real*();
        
        Vector& clear();
        
        static real angleBetween(Vector a, Vector b);
        
        friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    };
    
#include "vector.inl"
}


#endif /* vector_h */
