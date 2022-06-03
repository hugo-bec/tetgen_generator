
#include <stdio.h>


class particule {


  
    public:

        double x;
        double y;
        double z;

        particule(double _x, double _y, double _z) : 
        x(_x), y(_y), z(_z) {}

        ~particule();


};