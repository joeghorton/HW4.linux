cmake_minimum_required(VERSION 3.9)
project(HW4)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW4 main.cpp Category.h ClassicalMovie.h ComedyMovie.h Customer.h DramaMovie.h RentalStore.h
        Item.h MediaType.h Movie.h MovieStore.h HistoryNode.h MovieFactory.h ActionHandler.h ShelfNode.h)