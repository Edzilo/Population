#include "manipulation.h"


Personne* Manipulation::Reproduce(Personne* parentA,Personne* parentB,string name){


    int moyenneTailleParents = (parentA->getTaille() + parentB->getTaille())/2;
    int newTaille = moyenneTailleParents  + (0.1*(rand() % moyenneTailleParents  *  Manipulation::PileFace(rand() % moyenneTailleParents - moyenneTailleParents /2)));
    int taille = newTaille < 150 ? 150 : newTaille ;
    taille = taille > 200 ? 200 : taille ;
    ColorRGB moyenneEyeColor = ((parentA->eyeColor/2) + (parentB->eyeColor/2));
    ColorRGB moyenneHaircolor = ((parentA->haircolor/2) + (parentB->haircolor/2));
    ColorRGB eyecolor = ColorRGB(moyenneEyeColor.r * (0.9 + (rand()%20 /100.0) ),moyenneEyeColor.g * (0.9 + (rand()%20 /100.0) ) , moyenneEyeColor.b * (0.9 + (rand()%20 /100.0) )) ;
    ColorRGB haircolor = ColorRGB(moyenneHaircolor.r * (0.9 + (rand()%20 /100.0) ) , moyenneHaircolor.g * (0.9 + (rand()%20 /100.0) ) , moyenneHaircolor.b * (0.9 + (rand()%20 /100.0) ));

    Personne* child = new Personne(taille,haircolor,eyecolor,name);
    child->GetRandomName("/home/gcerba/ProjetsPerso/Genetique/Population/Names.txt");
    child->MutationRandom();

    return child;
}

string Manipulation::ReproduceName(string nameA,string nameB){


    string name = nameA + nameB;
    string newName;
    random_shuffle(name.begin(), name.end());
    do{
        newName = name.substr(0,/*name.length()/2*/ (int)(name.length() * (0.25 + (rand()%51 /100.0)) ));
    }while(newName.size() <= 2);


    // To lower
    std::transform (newName.begin(), newName.end(), newName.begin(), ::tolower);

    // Capitalize first
    std::transform (newName.begin(), newName.begin()+1, newName.begin(),  ::toupper);
    //std::transform (name.begin()+1, name.end(),   name.begin()+1,::tolower);


    return newName;


}

Personne* Manipulation::LookFor(Personne* personne , vector <Personne*> population){

    float ecartMin = population[0]->DifferenceCarre(personne);
    int index = 0;
    float difference;

    for(unsigned int i = 1 ; i < population.size()  ; i++){
        difference = population[i]->DifferenceCarre(personne);
        if(difference < ecartMin){
            ecartMin = difference;
            index = i;
        }
    }
    //std::cout<< "erreur minimale trouvee : "<< ecartMin<<endl;
    return population[index];
}

void Manipulation::OrderPopulation(vector <Personne*>  & population , Personne* ref){
    for(unsigned int i = 0 ; i < population.size() ; i ++){
        for(unsigned int j = i+1 ; j < population.size() ; j ++){
            if(population[j]->lessThan(population[i] , ref)){
                std::swap(population[i],population[j]);
            }
        }
        //std::cout << population[i]->DifferenceCarre(ref) << "," ;
    }
    //std::cout << endl;

}

vector<Personne*> Manipulation::newGeneration ( vector <Personne*> & population, float percentage /* valeur entre 0 et 100 */ , int taille_nouvelle_gen){
    vector <Personne*> newGen ;
    int index_reprod1;
    int index_reprod2;
    int taille_pop_init = population.size();
    int new_size;
    //Selection du top 10%
    for(int i = population.size() - 1; i > (int) (taille_pop_init * percentage/100.0) ; i --){
        //newGen.push_back(population[i]);
        delete population[i];
        population.pop_back();

    }

    new_size = population.size();

    for(uint j = 0 ; j < population.size() ; j++){
        newGen.push_back(population[j]);
    }

    //Reproduction à partir du top 10%
    for(int i = newGen.size() ; i < taille_nouvelle_gen ; i++){
        //index_reprod1 = rand() % ((int) (taille_pop_init * percentage/100.0));
        index_reprod1 = rand() % new_size;
        do{
            //index_reprod2 = rand() % ((int) (taille_pop_init * percentage/100.0));
            index_reprod2 = rand() % new_size;
        }while(index_reprod1 == index_reprod2);
        //newGen.push_back(Reproduce(newGen[index_reprod1],newGen[index_reprod2]));
        newGen.push_back(Reproduce(population[index_reprod1],population[index_reprod2]));
    }
    population.clear();
    vector<Personne*>().swap(population);
    return newGen;

}

void Manipulation::Afficher(vector <Personne*> population){
    for(unsigned int i = 0 ; i < population.size() ; i ++){
        population[i]->Afficher();

    }
    cout << endl; ;
}

