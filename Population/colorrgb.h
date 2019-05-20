#ifndef COLORRGB_H
#define COLORRGB_H

#include <iostream>
using namespace std;

class ColorRGB
{
public:
    int r;
    int g;
    int b;
    ColorRGB();
    ColorRGB(int,int,int);
    ColorRGB operator+ (const ColorRGB&) const;
    ColorRGB operator- (const ColorRGB&) const;
    ColorRGB operator/ (const int) const;
    ColorRGB operator* (const int) const;
    ColorRGB operator* (const float) const;
    float distanceCarre ( const ColorRGB& )const;

    void Afficher();
};

#endif // COLORRGB_H
