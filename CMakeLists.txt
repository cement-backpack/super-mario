cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

project (Mario-Allegro
	VERSION 0.0.1
	LANGUAGES CXX
	)

set (CMAKE_CXX_STANDARD 11)

add_executable (Mario-Allegro
	src/bitmap.cpp
	src/block.cpp
	src/brick.cpp
	src/bush.cpp
	src/castle.cpp
	src/cloud.cpp
	src/enemy.cpp
	src/flag.cpp
	src/gameobject.cpp
	src/gamescreen.cpp
	src/hill.cpp
	src/inputmanager.cpp
	src/main.cpp
	src/map.cpp
	src/maploader.cpp
	src/mario.cpp
	src/mariosprite.cpp
	src/owl.cpp
	src/pipe.cpp
	src/point.cpp
	src/rectangle.cpp
	src/secretbox.cpp
	src/soundmanager.cpp
	src/turtle.cpp
	src/wall.cpp
	)

target_link_libraries (Mario-Allegro
	allegro
	allegro_acodec
	allegro_audio
	allegro_dialog
	allegro_image
	)
