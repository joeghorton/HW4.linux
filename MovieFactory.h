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


class MovieFactory {

public:
    Movie* createMovie(char category, string director, string title, int year);

    Movie* createClassicalMovie(string director, string title, string actorFirst,
                                        string actorLast, int month, int year);


};


Movie* MovieFactory::createMovie(char category, string director, string title, int year) {
    if (category == 'F') {
        return new ComedyMovie(title, director, year);
    } else if (category == 'D') {
        return new DramaMovie(title, director, year);
    } else {
        return NULL;
    }
}

Movie* MovieFactory::createClassicalMovie(string director, string title, string actorFirst, string actorLast,
                                                int month, int year) {
    return new ClassicalMovie(title, director, year, month, actorFirst, actorLast);
}


#endif //HW4_MOVIEFACTORY_H
