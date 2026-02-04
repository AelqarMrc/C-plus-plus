#include <stdlib.h>
#include <stdbool.h>
#include <cassert>
#include <iostream>

struct Vector
{

public:
    // ATTRIBUTES ET CONSTRUCTEUR
    float x, y;
    Vector(float abs, float ord): x(abs), y(ord) {};

    
    // SURCHAGRE D'OPERATEUR
    friend Vector operator+(const Vector u,const Vector v){
        return Vector((u.x+v.x),(u.y+v.y));
    }
    
    friend Vector operator*(const Vector u, float a){
        return Vector((u.x*a),(u.y*a));
    }       // POUR LA COMMUTATIVITE 
    friend Vector operator*(float a, const Vector u){
        return Vector((u.x*a),(u.y*a));
    }
};

// METHODES
static float scal(const Vector& u, const Vector& v){
    return (u.x*v.x)+(u.y*v.y); 
}
struct Base2d
{

public:
    Vector i, j;
    Base2d(const Vector& u, const Vector& v): i(u), j(v) {}

    bool estOrtho(const Base2d& b){
        if(scal(b.i, b.j) == 0)
            return true;
        else   
            return false;
    };

    //SURCHARGE OPERATEUR 
    friend std::ostream& operator<<(std::ostream& os, const Base2d& b){
        os << "Base( i(" << b.i.x << "," << b.j.y << "), j(" << b.j.x << "," << b.j.y << ") )";
        return os;
    }

    Vector operator()(float x, float y)const{
        return (i*x) + (j*y);
    }
};

int main() {
    return EXIT_SUCCESS;
}


