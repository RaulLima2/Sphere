#ifndef SPHERE_H
#define SPHERE_H

typedef struct Sphere Sphere;

Sphere* constructor(int slices, int stacks, double radius, double x, double y, double z);

//Getters
double getRadius(Sphere* sphere);
double getX(Sphere* sphere);
double getY(Sphere* sphere);
double getZ(Sphere* sphere);
int getSlices(Sphere* sphere);
int getStacks(Sphere* sphere);

//Setters
void setRadius(Sphere* sphere, double radius);
void setX(Sphere* sphere, double x);
void setY(Sphere* sphere, double y);
void setZ(Sphere* sphere, double z);
void setSlices(Sphere* sphere, int slices);
void setStacks(Sphere* sphere, int stacks);

void destructor(Sphere* sphere);


#endif // SPHERE_H