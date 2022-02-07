#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "sphere.h"

typedef struct Sphere{
    int slices;
    int stacks;
    double x;
    double y;
    double z;
    double radius;
};

Sphere* constructor(int slices, int stacks, double radius, double x, double y, double z) {
    Sphere* s = malloc(sizeof(Sphere));
    
    if (s == NULL) {
        printf("Error: could not allocate memory for Sphere.\n");
        exit(1); 
    } else {
        s->slices = slices;
        s->stacks = stacks;
        s->radius = radius;
        s->x = x;
        s->y = y;
        s->z = z;
    }

    return s;
}

//Getters
double getRadius(Sphere* sphere) {
    return sphere->radius;
}

double getX(Sphere* sphere) {
    return sphere->x;
}

double getY(Sphere* sphere) {
    return sphere->y;
}

double getZ(Sphere* sphere) {
    return sphere->z;
}

int getSlices(Sphere* sphere) {
    return sphere->slices;
}

int getStacks(Sphere* sphere) {
    return sphere->stacks;
}

//Setters
void setRadius(Sphere* sphere, double radius) {
    sphere->radius = radius;
}

void setX(Sphere* sphere, double x) {
    sphere->x = x;
}

void setY(Sphere* sphere, double y) {
    sphere->y = y;
}

void setZ(Sphere* sphere, double z) {
    sphere->z = z;
}

void setSlices(Sphere* sphere, int slices) {
    sphere->slices = slices;
}

void setStacks(Sphere* sphere, int stacks) {
    sphere->stacks = stacks;
}

void destructor(Sphere* sphere) {
    free(sphere);
}
