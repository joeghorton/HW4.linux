//
// Created by Joe on 3/3/18.
//

#include <fstream>
#include "Movie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicalMovie.h"

#ifndef HW4_MOVIEFACTORY_H
#define HW4_MOVIEFACTORY_H

using namespace std;


class MovieFactory {

public:

    DramaMovie* createDramaMovie(string director, string title, int year);

    DramaMovie* createDramaMovie(string director, string title);

    ComedyMovie* createComedyMovie(string title, int year);

    ComedyMovie* createComedyMovie(string director, string title, int year);

    ClassicalMovie* createClassicalMovie(string director, string title, string actorFirst,
                                                string actorLast, int month, int year);


};

#endif //HW4_MOVIEFACTORY_H