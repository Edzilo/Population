#include "colorrgb.h"
#include "math.h"

ColorRGB::ColorRGB(){ 
    r = 0;
    g = 0;
    b = 0;
}

ColorRGB::ColorRGB(int red,int green,int blue){
    r = red > 255 ? 255 : red;
    g = green > 255 ? 255 : green;
    b = blue > 255 ? 255 : blue;
}

ColorRGB ColorRGB::operator+ (const ColorRGB& other) const{
    int newRed,newGreen,newBlue;
    newRed = (this->r + other.r) < 255 ? this->r + other.r : 255;
    newGreen = (this->g + other.g) < 255 ? this->g + other.g : 255;
    newBlue = (this->b + other.b) < 255 ? this->b + other.b : 255;
    return ColorRGB(newRed,newGreen,newBlue);
}

ColorRGB ColorRGB::operator- (const ColorRGB& other) const{
    int newRed,newGreen,newBlue;
    newRed = (this->r - other.r) > 0 ? this->r - other.r : 0;
    newGreen = (this->g - other.g) > 0 ? this->g - other.g : 0;
    newBlue = (this->b - other.b) > 0 ? this->b - other.b : 0;
    return ColorRGB(newRed,newGreen,newBlue);
}

ColorRGB ColorRGB::operator/(const int diviseur) const{
    int newRed,newGreen,newBlue;
    newRed = (this->r /diviseur) < 255 ? this->r /diviseur : 255;
    newGreen = (this->g /diviseur) < 255 ? this->g /diviseur : 255;
    newBlue = (this->b /diviseur) < 255 ? this->b /diviseur : 255;
    return ColorRGB(newRed,newGreen,newBlue);
    //return ColorRGB(this->r/diviseur,this->g/diviseur,this->b/diviseur);

}

ColorRGB ColorRGB::operator* (const int facteur) const{
    int newRed,newGreen,newBlue;
    newRed = (this->r *facteur) < 255 ? this->r *facteur : 255;
    newGreen = (this->g *facteur) < 255 ? this->g *facteur : 255;
    newBlue = (this->b *facteur) < 255 ? this->b *facteur : 255;

    cout <<  "newRed int " << (newRed) << endl;
    return ColorRGB(newRed,newGreen,newBlue);

    //return ColorRGB(this->r*facteur,this->g*facteur,this->b*facteur);
}

ColorRGB ColorRGB::operator* (const float facteur) const{
    int newRed,newGreen,newBlue;
    newRed = (this->r *facteur) < 255 ? this->r *facteur : 255;
    newGreen = (this->g *facteur) < 255 ? this->g *facteur : 255;
    newBlue = (this->b *facteur) < 255 ? this->b *facteur : 255;
    cout <<  "newRed float " << (newRed) << endl;

    return ColorRGB(newRed,newGreen,newBlue);
    //return ColorRGB((int)this->r*facteur,(int)this->g*facteur,(int)this->b*facteur);
}


void ColorRGB::Afficher(){
    cout << r << " " << g << " " << b;
}

//  std::cout<<"purple vaut " << std::hex << purple << std::dec << endl;

float ColorRGB::distanceCarre ( const ColorRGB& other )const {
    return 50 * sqrt((r - other.r)*(r - other.r) + (g - other.g)*(g - other.g) + (b - other.b)*(b - other.b)) / sqrt(255*255*255) ;
}


