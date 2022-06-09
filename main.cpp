
#include <stdio.h>
#include <vector>
#include <iostream>
#include<random>
#include "tetgen_lib/tetgen.h"
#include "particule.cpp"

int main(int argc, char const *argv[])
{
    int _nbparticules = 10;
    int _dimCage = 10;


    std::vector<particule*> _particules;



    for (int i = 0; i < _nbparticules; i++)
    {
        // src : https://stackoverflow.com/questions/686353/random-float-number-generation
        
        _particules.push_back(new particule(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * _dimCage ,
                                            static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * _dimCage, 
                                            static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * _dimCage));
        
        std::cout<<_particules[i]->x<<std::endl;
        std::cout<<_particules[i]->y<<std::endl;
        std::cout<<_particules[i]->z<<std::endl;
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
    //param[ 0 ]	 = '';
    param[ 0 ]	 = '\0';
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
