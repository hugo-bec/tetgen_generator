
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
    tetgenio in, out;
    in.initialize();
    out.initialize();
    in.numberofpoints = _nbparticules;
    in.pointlist	  = new REAL[ in.numberofpoints * 3 ];

    for ( int i = 0; i < _nbparticules; i++ )
    {
        in.pointlist[ 3 * i ]	  = _particules[ i ]->x;
        in.pointlist[ 3 * i + 1 ] = _particules[ i ]->y;
        in.pointlist[ 3 * i + 2 ] = _particules[ i ]->z;
    }

    char * param = new char[ 2 ];
    param[ 0 ]	 = 'V';
   /* param[ 1 ]	 = 'e';
    param[ 2 ]	 = 'e';*/
    param[ 1 ]	 = '\0';
    tetrahedralize( param, &in, &out );
    out.save_poly("tetra");
    out.save_nodes("tetra");
    //tetrahedralize( param, &in, &tmp );

    /*char * param2 = new char[ 10 ];
    param2[ 0 ]	 = 'q';
    param2[ 1 ]	 = '\0';
    tetrahedralize( param2, &tmp, NULL );*/

    //tetrahedralize( param, &out, NULL );
    
    return 0;
}
