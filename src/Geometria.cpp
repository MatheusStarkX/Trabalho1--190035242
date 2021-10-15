#include "Geometria.h"

Vet2::Vet2(float x, float y){
    this->x = x;
    this->y = y;
}

void Vet2::Soma(Vet2 *vetor){
    x += vetor->x;
    y += vetor->y;
}

void Vet2::Sub(Vet2 *vetor){
    x -= vetor->x;
    y -= vetor->y; 
}

void Vet2::Mult(float escalar){
    x *= escalar;
    y *= escalar;
}

float Vet2::GetModulo(){
    return sqrt(pow(x,2) + pow(y,2));
}

float Vet2::GetAngulo(){
    return atan2(y,x);
}

float *Vet2::Norma(float *norma){
    float modulo = GetModulo();
    norma[0] = x/modulo;
    norma[1] = y/modulo;
    return norma;
}

float Vet2::Dist(Vet2 *vetor){
    return sqrt(pow(x - vetor->x,2) + pow(y - vetor->y,2));
}

Vet2 Vet2::Rotacao(float rad){
    //float rad = GetAngulo() * 180/ M_PI;
    x = x*cos(rad) - y*sin(rad);
    y = y*cos(rad) + x*sin(rad);
    return Vet2(x,y);
}

Vet2 Vet2::operator+ (Vet2 v){
    return Vet2(x + v.x, y + v.y);
}

Vet2 Vet2::operator- (Vet2 v){
    return Vet2(x - v.x, y - v.y);
}

Rect::Rect(){

}

Rect::Rect(float CSEx, float CSEy, float Larg, float Alt){
    this->CSEx = CSEx;
    this->CSEy = CSEy;
    this->Larg = Larg;
    this->Alt = Alt;
}

Vet2 Rect::Centro(){
    float x = CSEx + Larg/2;
    float y = CSEy + Alt/2;
    return Vet2(x,y);
}

float Rect::DistCentro(Rect *obj, Rect *obj2){
    return sqrt(pow(obj->Centro().x - obj2->Centro().x,2) + pow(obj->Centro().y - obj2->Centro().y,2));
}

bool Rect::EstaDentro(float x, float y){
    if (x > CSEx && x < (CSEx + Larg) && y > CSEy && y < (CSEy + Alt))
        return true;
    return false; 
}

// Falta a soma de rect com vetor (Rect) e a inclinação da reta dada por 2 pontos (Vet2)