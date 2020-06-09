#ifndef POLYGON_H
#define POLYGON_H

class Polygon
{
protected:
    int _numSides;
    int* _sides;
public:
    Polygon();
    Polygon(int sides);
    Polygon(const Polygon& p);
    ~Polygon();
    int GetNumSides() const;
    int* GetSides() const; //this is going to have some complications. We don't want to return pointer to some private data, we want to return something else. We also don't want to return a new pointer that has to be deleted later. ~?~
    int Perimeter() const;
    bool operator==(const Polygon& other) const;
};

#endif