
#include <stdio.h>
#include <vector>
#include <iostream>
#include "tetgen_lib/tetgen.h"
#include "particule.cpp"

int main(int argc, char const *argv[])
{
    int _nbparticules = 10000;
    int _dimCage = 10;


    std::vector<particule*> _particules;

    for (int i = 0; i < _nbparticules; i++)
    {
        _particules.push_back(new particule(rand() * _dimCage , rand() * _dimCage, rand() * _dimCage));
    }
    tetgenio in, out;
    in.initialize();
   // out.initialize();
    in.numberofpoints = _nbparticules;
    in.pointlist	  = new REAL[ in.numberofpoints * 3 ];

    for ( int i = 0; i < _nbparticules; i++ )
    {
        in.pointlist[ 3 * i ]	  = _particules[ i ]->x;
        in.pointlist[ 3 * i + 1 ] = _particules[ i ]->y;
        in.pointlist[ 3 * i + 2 ] = _particules[ i ]->z;
    }

    char * param = new char[ 10 ];
    param[ 0 ]	 = 'w';
    param[ 1 ]	 = '\0';
    //param[ 2 ]	 = '\0';
    //tetrahedralize( param, &in, &out );
    tetrahedralize( param, &in, NULL );

    /*printf("nombre aretes: %d\n", out.numberofedges);
    printf("nombre facets: %d\n", out.numberoffacets);
    printf("nombre tetrahedre: %d\n", out.numberoftetrahedra);
    printf("nombre points: %d\n", out.numberofpoints);
    out.save_poly("tetra");
    out.save_nodes("tetra");*/
    
    return 0;
}
