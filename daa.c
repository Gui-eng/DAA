#include <stdio.h>
#include <Windows.h>

typedef struct vector{
    float x;
    float y;
    float z;
}Vector3D;

float fast_inverse_sqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;           // Interpret bits as an integer.
    i = 0x5f3759df - (i >> 1);   // Magic number for approximation.
    x = *(float*)&i;             // Interpret back as a floating-point number.
    x = x * (1.5f - xhalf * x * x); // Newton-Raphson iteration to improve accuracy.
    return x;
}

void normalize(Vector3D* vector) {
    float magnitude_squared = vector->x * vector->x + vector->y * vector->y + vector->z * vector->z;
    float inv_magnitude = fast_inverse_sqrt(magnitude_squared);

    vector->x *= inv_magnitude;
    vector->y *= inv_magnitude;
    vector->z *= inv_magnitude;
}

int main(){
    
}


