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
include_directories("/usr/include/gconf/2/")



FIND_PACKAGE(CURL REQUIRED)
	include_directories(${CURL_INCLUDE_DIRS})


#-----libglade------https://www.opensync.org/browser/branches/3rd-party-cmake-modules/modules/FindLibGlade.cmake?rev=3475
	INCLUDE( FindPkgConfig )
	
	IF ( LibGlade_FIND_REQUIRED )
	        SET( _pkgconfig_REQUIRED "REQUIRED" )
	ELSE( LibGlade_FIND_REQUIRED )
	        SET( _pkgconfig_REQUIRED "" )   
	ENDIF ( LibGlade_FIND_REQUIRED )
	
	IF ( LIBGLADE_MIN_VERSION )
	        PKG_SEARCH_MODULE( LIBGLADE ${_pkgconfig_REQUIRED} libglade-2.0>=${LIBGLADE_MIN_VERSION} )
	ELSE ( LIBGLADE_MIN_VERSION )
	        PKG_SEARCH_MODULE( LIBGLADE ${_pkgconfig_REQUIRED} libglade-2.0 )
	ENDIF ( LIBGLADE_MIN_VERSION )
	
	
	IF( NOT LIBGLADE_FOUND AND NOT PKG_CONFIG_FOUND )
	        FIND_PATH(LIBGLADE_INCLUDE_DIRS glade/glade.h )
	        FIND_LIBRARY( LIBGLADE_LIBRARIES glade-2.0)
	
	        # Report results
	        IF ( LIBGLADE_LIBRARIES AND LIBGLADE_INCLUDE_DIRS )     
	                SET( LIBGLADE_FOUND 1 )
	                IF ( NOT LIBGLADE_FIND_QUIETLY )
	                        MESSAGE( STATUS "Found LIBGLADE: ${LIBGLADE_LIBRARIES}" )
	                ENDIF ( NOT LIBGLADE_FIND_QUIETLY )
	        ELSE ( LIBGLADE_LIBRARIES AND LIBGLADE_INCLUDE_DIRS )   
	                IF ( LibGlade_FIND_REQUIRED )
	                        MESSAGE( SEND_ERROR "Could NOT find LIBGLADE" )
	                ELSE ( LibGlade_FIND_REQUIRED )
	                        IF ( NOT LIBGLADE_FIND_QUIETLY )
	                                MESSAGE( STATUS "Could NOT find LIBGLADE" )     
	                        ENDIF ( NOT LIBGLADE_FIND_QUIETLY )
	                ENDIF ( LibGlade_FIND_REQUIRED )
	        ENDIF ( LIBGLADE_LIBRARIES AND LIBGLADE_INCLUDE_DIRS )
	ENDIF( NOT LIBGLADE_FOUND AND NOT PKG_CONFIG_FOUND )   
	
	# Hide advanced variables from CMake GUIs
	MARK_AS_ADVANCED( LIBGLADE_LIBRARIES LIBGLADE_INCLUDE_DIRS )
#-----libglade------https://www.opensync.org/browser/branches/3rd-party-cmake-modules/modules/FindLibGlade.cmake?rev=3475

ADD_EXECUTABLE(tangogis ${PROJECT_SOURCE_LIST})
#target_link_libraries(tangogis gtk glade curl sqlite) 
target_link_libraries(tangogis 
								${GTK2_LIBRARIES} 
								${LIBGLADE_LIBRARIES}
								${CURL_LIBRARIES}
								sqlite3
								gconf-2
								exif
								)


message(STATUS "Package name: " ${PROJECT_NAME})
message(STATUS "Version:      " ${${PROJECT_NAME}_VERSION_})

add_definitions(-DHAVE_CONFIG_H)
include(CheckIncludeFile)
check_include_file("config.h" CONF_H)
set(PACKAGE_LOCALE_DIR 1)
set(PACKAGE_DATA_DIR 1)
set(PACKAGE_PIXMAPS_DIR 1)
set(GETTEXT_PACKAGE 1)
set(INTERFACE_NONINSTALL_PATH 1)
set(INTERFACE_INSTALL_PATH 1)
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
include_directories(${PROJECT_BINARY_DIR})

install(TARGETS tangogis RUNTIME DESTINATION bin)
install(FILES ${PROJECT_SOURCE_DIR}/src/interface.glade DESTINATION ${SHARE}${PROJECT_NAME})
