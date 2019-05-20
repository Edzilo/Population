#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <time.h>
#include <iostream>
#include "colorrgb.h"
#include <iostream>
#include <fstream>


using namespace std;


class Personne
{


public:
    Personne(string newName = "defaut");
    Personne( int taille, ColorRGB couleur,ColorRGB eyecolor, string newName = "defaut");
    void Afficher();
    int getTaille();
    string getName(){return name;}
    float DifferenceCarre( Personne* other);
    bool lessThan ( Personne* other ,  Personne* ref);
    string GetRandomName(string filename);
    void MutationRandom();




    string name;
    ColorRGB haircolor;
    int taille;
    ColorRGB eyeColor;
};

#endif // PERSONNE_H
