#include "personne.h"
#include <math.h>

int MutationRandomfactor = 500;

Personne::Personne(string newName)
{
    name = newName;
    taille = rand() % 50 + 150;
    eyeColor = ColorRGB(rand() % 256 , rand() % 256 , rand() % 256);
    haircolor = ColorRGB(rand() % 256 , rand() % 256 , rand() % 256);
    if(name=="defaut")name = GetRandomName("/home/gcerba/ProjetsPerso/Genetique/Population/Names.txt");
}

Personne::Personne( int newtaille, ColorRGB newhaircolor,ColorRGB neweyecolor, string newName){
    name = newName;
    taille = newtaille;
    haircolor = newhaircolor;
    eyeColor = neweyecolor;
    if(name=="defaut")name = GetRandomName("/home/gcerba/ProjetsPerso/Genetique/Population/Names.txt");

    // /home/gcerba/ProjetsPerso/Genetique/Population/Names.txt
}

void Personne::Afficher(){
    cout << name << " de taille " << taille << " cm les cheveux ";
    haircolor.Afficher();
    cout<< " et les yeux ";
    eyeColor.Afficher();
    cout<<endl;
}

int Personne::getTaille() {return taille ;}

float Personne::DifferenceCarre(Personne* other){
    return this->eyeColor.distanceCarre(other->eyeColor) +  abs(taille - other->taille) + this->haircolor.distanceCarre(other->haircolor);
}

bool Personne::lessThan (Personne* other , Personne* ref){
    return (this->DifferenceCarre(ref) < other->DifferenceCarre(ref));

}

string Personne::GetRandomName(string filename){

    ifstream myfile(filename);
    string line;
    int compteur = 1;
    getline(myfile, line);
    int nb_lines = atoi(line.c_str());
    int numero = rand() % nb_lines +1;
    while (getline(myfile, line) && compteur != numero){
        compteur ++;
    }
    //cout<< "nom choisi " << line << "a la ligne " << compteur << endl;
    return line;
}

void Personne::MutationRandom(){

    // taille , eye.r , eye.g , eye.b , hair.r , hair.g , hair.b
    int modifications[7];


    int valeur = rand()%MutationRandomfactor +1; // 1 chance sur MutationRandomfactor de muter aléatoirement
    if(valeur == 1){
        for(uint i = 0 ; i < 7 ; i ++)modifications[i] = rand()%2;
        if(modifications[0] == 0)taille = rand() % 50 + 150;
        if(modifications[1] == 0)eyeColor.r = rand() % 256;
        if(modifications[2] == 0)eyeColor.g = rand() % 256;
        if(modifications[3] == 0)eyeColor.b = rand() % 256;
        if(modifications[4] == 0)haircolor.r = rand() % 256;
        if(modifications[5] == 0)haircolor.g = rand() % 256;
        if(modifications[6] == 0)haircolor.b = rand() % 256;
    }
}
