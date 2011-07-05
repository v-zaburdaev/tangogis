cmake_minimum_required(VERSION 2.8)
#PROJECT (prog C)
PROJECT (tangogis)
# The version number.
set (tangogis_VERSION_MAJOR 1.0)
set (Tutorial_VERSION_MINOR 0)

set (PROJECT_SOURCE_LIST src/main.c 
						src/callbacks.c 
						src/converter.c 
						src/exif.c 
						src/friends.c 
						src/geo_photos.c 
						src/globals.c 
						src/gps_functions.c 
						src/init.c 
						src/interface.c 
						src/map_management.c 
						src/poi.c 
						src/support.c 
						src/tile_management.c 
						src/tracks.c 
						src/util.c 
						src/wp.c)

FIND_PACKAGE(GTK2 REQUIRED gtk)
      include_directories(${GTK2_INCLUDE_DIRS})
      target_link_libraries(tangogis ${GTK2_LIBRARIES})
include_directories("/usr/include/gconf/2/")
add_definitions(-DPACKAGE_DATA_DIR )

FIND_PACKAGE(CURL REQUIRED)
      include_directories(${CURL_INCLUDE_DIRS})

ADD_EXECUTABLE(tangogis ${PROJECT_SOURCE_LIST})
target_link_libraries(tangogis ${GTK2_LIBRARIES} ${CURL_LIBRARIES})

configure_file(config.h.in config.h)
