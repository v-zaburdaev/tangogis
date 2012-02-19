cmake_minimum_required(VERSION 2.8)
#PROJECT (prog C)
PROJECT (tangogis C)
add_definitions(-std=gnu99 -g -O0)
# The version number.
set (tangogis_VERSION_ 1.0.0)

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


FIND_PACKAGE(CURL REQUIRED)
	include_directories(${CURL_INCLUDE_DIRS})


ADD_EXECUTABLE(tangogis ${PROJECT_SOURCE_LIST})
#target_link_libraries(tangogis gtk glade curl sqlite) 
target_link_libraries(tangogis 
								${GTK2_LIBRARIES} 
								${LIBGLADE_LIBRARIES}
								${CURL_LIBRARIES}
								sqlite3
								exif
								m
								gthread-2.0
								)


message(STATUS "Package name: " ${PROJECT_NAME})
message(STATUS "Version:      " ${${PROJECT_NAME}_VERSION_})

add_definitions(-DHAVE_CONFIG_H)
include(CheckIncludeFile)
set(PACKAGE_LOCALE_DIR 1)
set(PACKAGE_DATA_DIR 1)
set(PACKAGE_PIXMAPS_DIR 1)
set(GETTEXT_PACKAGE 1)
set(INTERFACE_NONINSTALL_INTERFACE_PATH 1)
set(INTERFACE_INSTALL_INTERFACE_PATH 1)
set (SHARE ${CMAKE_INSTALL_PREFIX}/share/)
set (ENABLE_NLS 1)
set (PACKAGE_STRING 1)
set (VERSION 1)
#set(HAVE_BIND_TEXTDOMAIN_CODESET 1)
#set(HAVE_DCGETTEXT 1)
#set(HAVE_DLFCN_H 1)
#set(HAVE_GETTEXT 1)
#set(HAVE_INTTYPES_H 1)
#set(HAVE_LC_MESSAGES 1)
#set(HAVE_LOCALE_H 1)
#set(HAVE_MEMORY_H 1)
#set(HAVE_STDINT_H 1)
#set(HAVE_STDLIB_H 1)
#set(HAVE_STRINGS_H 1)
#set(HAVE_STRING_H 1)
#set(HAVE_SYS_STAT_H 1)
#set(HAVE_SYS_TYPES_H 1)
#set(HAVE_UNISTD_H 1)
#set(STDC_HEADERS 1)
configure_file(config.h.in config.h) 
check_include_file("config.h" CONF_H)
include_directories(${PROJECT_BINARY_DIR})

INSTALL_FILES(/share/tangogis FILES ${project_source_dir}src/interface.glade)
INSTALL_TARGETS(/bin tangogis)


add_custom_target(uninstall 
	COMMAND	rm -rf ${CMAKE_INSTALL_PREFIX}/{bin/tangogis,share/tangogis/})

