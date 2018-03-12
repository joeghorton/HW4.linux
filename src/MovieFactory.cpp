//
// Created by Joe on 3/11/18.
//

#include "../hdr/MovieFactory.h"

DramaMovie* MovieFactory::createDramaMovie(string director, string title, int year) {
    return new DramaMovie(director, title, year);
}

DramaMovie* MovieFactory::createDramaMovie(string director, string title) {
    return createDramaMovie(director, title, -1);
}

ComedyMovie* MovieFactory::createComedyMovie(string director, string title, int year) {
    return new ComedyMovie(title, director, year);
}

ComedyMovie* MovieFactory::createComedyMovie(string title, int year) {
    return createComedyMovie("", title, year);
}

ClassicalMovie* MovieFactory::createClassicalMovie(string director, string title, string actorFirst, string actorLast,
                                                            int month, int year) {
    return new ClassicalMovie(title, director, year, month, actorFirst, actorLast);
}