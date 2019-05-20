#include <iostream>
#include "personne.h"
#include "manipulation.h"

using namespace std;

int taille_population = 200;
float palier = 0.005;
//float palier = 0.025;
//Pour une population de 200
//toutes le composantes de couleurs égales : 0.075 : ColorRGB(127, 127, 127) , ColorRGB(127, 127, 127)
//écarts moyens sur les composantes de couleurs : 0.035 (127 pts d'écart) : ColorRGB(127, 127, 255) , ColorRGB(127, 127, 255)
//écarts moyens sur les composantes de couleurs : 0.00 (127 pts d'écart minimum entre toutes les compo) : ColorRGB(0, 127, 255) , ColorRGB(127, 0, 255)
//écarts très importants sur les composantes de couleurs : 0.00 (255 pts d'écart) : ColorRGB(255, 0, 0) , ColorRGB(0, 0, 255)

int main(){
    srand (time(NULL));
    vector <Personne*> population;
    Manipulation manipulateur;

    for(int i = population.size() ; i < taille_population ; i++){
        population.push_back(new Personne());
    }
    cout<< "taille de la gen : " << population.size() << endl;
    Personne* desired = new Personne(175 , ColorRGB(0, 127, 255) , ColorRGB(127, 0, 255));

    float erreur = 10000;
    for(int i = 0 ; i < 5000 && erreur > palier ; i++){
        manipulateur.OrderPopulation(population,desired);
        population = manipulateur.newGeneration(population,10,taille_population);
        Personne* match = manipulateur.LookFor(desired,population);
        erreur = match->DifferenceCarre(desired);
        //if (i % 10 == 0)
            //cout<< i << ") erreur : " << erreur <<endl;
        //cout<< "votre personne ideale est " << endl;
        if(erreur <= palier ){
            cout << "Trouvé à la génération " << i << endl;
            match->Afficher();
        }
    }

    cout << "sortie du for" << endl;

    //cout<< "taille de la nouvelle gen : " << population.size() << endl;
    manipulateur.OrderPopulation(population,desired);
    //manipulateur.Afficher(population);
    population[0]->Afficher();

    vector<Personne*>().swap(population);
    delete desired;
    //delete match;

}
