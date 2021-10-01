#include "cmath"

#ifndef GEOMETRIA_H
#define GEOMETRIA_H
#define _USE_MATH_DEFINES

class Vet2 {
    private:
        float norma[2];
    public:
        float x, y;
        Vet2(float x, float y);
        void Soma(Vet2 *vetor);
        void Sub(Vet2 *vetor);
        void Mult(float escalar);
        float GetModulo();
        float GetAngulo();
        float *Norma(float *norma);
        float Dist(Vet2 *vetor);
        Vet2 Rotacao(float rad);
        Vet2 operator + (Vet2 v);
        Vet2 operator - (Vet2 v);
};

class Rect {
    private:
        float centro[2];
    public:
        float CSEx, CSEy, Larg, Alt;
        Rect();
        Rect(float CSEx, float CSEy, float Larg, float Alt);
        float *Centro(float *centro);
        float DistCentro(Rect *obj, Rect *obj2);
        bool EstaDentro(float x, float y);
};

#endif