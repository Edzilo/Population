#ifndef MANIPULATION_H
#define MANIPULATION_H

#include "personne.h"


#include <algorithm>
#include <string>
#include <vector>





class Manipulation
{
public:
    Personne* Reproduce(Personne*,Personne*,string name = "defaut");
    string ReproduceName(string,string);
    int PileFace(int valeur){
        //std::cout << "PileFace retourne " << (valeur < 0 ?  -1 :  1) << endl;
        return valeur < 0 ?  -1 :  1;
    }

    Personne* LookFor(Personne* , vector <Personne*>);
    void OrderPopulation(vector <Personne*> &, Personne* ref);
    vector<Personne*> newGeneration ( vector <Personne*> &, float percentage , int taille_nouvelle_gen);
    void Afficher(vector <Personne*>);


};

#endif // MANIPULATION_H
