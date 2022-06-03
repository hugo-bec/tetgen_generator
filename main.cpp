
#include <stdio.h>
#include <vector>
#include <iostream>
#include "tetgen_lib/tetgen.h"
#include "particule.cpp"

int main(int argc, char const *argv[])
{
    int _nbparticules = 100;
    int _dimCage = 10;


    std::vector<particule*> _particules;

    for (int i = 0; i < _nbparticules; i++)
    {
        _particules.push_back(new particule(rand() * _dimCage , rand() * _dimCage, rand() * _dimCage));
    }
    tetgenio in;
    in.initialize();
    in.numberofpoints = _nbparticules;
    in.pointlist	  = new REAL[ in.numberofpoints * 3 ];

    for ( int i = 0; i < _nbparticules; i++ )
    {
        in.pointlist[ 3 * i ]	  = _particules[ i ]->x;
        in.pointlist[ 3 * i + 1 ] = _particules[ i ]->y;
        in.pointlist[ 3 * i + 2 ] = _particules[ i ]->z;
    }

    char * param = new char[ 5 ];
    param[ 0 ]	 = 'v';
    param[ 1 ]	 = 'e';
    param[ 2 ]	 = 'e';
    param[ 3 ]	 = 'Q';
    param[ 4 ]	 = '\0';
    tetrahedralize( "", &in, NULL );
    return 0;
}
