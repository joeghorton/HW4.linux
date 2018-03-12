cmake_minimum_required(VERSION 3.9)
project(HW4)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW4 src/main.cpp hdr/Category.h hdr/ClassicalMovie.h hdr/ComedyMovie.h hdr/Customer.h hdr/DramaMovie.h hdr/RentalStore.h
        hdr/Item.h hdr/MediaType.h hdr/Movie.h hdr/MovieStore.h hdr/HistoryNode.h hdr/MovieFactory.h hdr/ShelfNode.h src/Category.cpp
        src/ClassicalMovie.cpp src/ComedyMovie.cpp src/Customer.cpp src/DramaMovie.cpp src/HistoryNode.cpp src/Item.cpp src/MediaType.cpp
        src/Movie.cpp src/MovieFactory.cpp src/MovieStore.cpp src/RentalStore.cpp src/ShelfNode.cpp)