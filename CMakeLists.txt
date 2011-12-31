cmake_minimum_required( VERSION 2.6 )
project( srLEngine )
set( PROJECT_VERSION "0.5" )
set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR} )

find_package(OpenGL)
find_package(Freetype)
# find_package(Ruby)

include_directories(${CMAKE_CURRENT_LIST_DIR}/includes)
include_directories(${FREETYPE_INCLUDE_DIR})
# include_directories(${RUBY_INCLUDE_DIR})


configure_file(${CMAKE_CURRENT_LIST_DIR}/Config.cmake ${CMAKE_CURRENT_LIST_DIR}/includes/SRL/generalConfig.hpp)


aux_source_directory( src/ 			BASE_SOURCE_FILES )
aux_source_directory( src/windowing WINDOWING_SOURCE_FILES )
aux_source_directory( src/opengl 	OPENGL_SOURCE_FILES )
aux_source_directory( src/3d 		3D_SOURCE_FILES )
aux_source_directory( src/gui	 	GUI_SOURCE_FILES )
aux_source_directory( src/SOIL		SOIL_SOURCE_FILES )

if( WIN32 )
	list( REMOVE_ITEM OPENGL_SOURCE_FILES src/opengl/glxContext.cpp)
	list( REMOVE_ITEM WINDOWING_SOURCE_FILES src/windowing/windowX.cpp)
elseif( UNIX OR APPLE )
	list( REMOVE_ITEM OPENGL_SOURCE_FILES src/opengl/wglContext.cpp)
	list( REMOVE_ITEM WINDOWING_SOURCE_FILES src/windowing/windowWin32.cpp)
endif( WIN32 )

list( REMOVE_ITEM BASE_SOURCE_FILES src/res.cpp)



set( LIBRARY_OUTPUT_PATH lib/)
set( SRL_HOMEMADE_EXT FALSE)

add_library(
	srl
	SHARED
	${WINDOWING_SOURCE_FILES}
	${OPENGL_SOURCE_FILES}
	${GUI_SOURCE_FILES}
	${3D_SOURCE_FILES}
	${BASE_SOURCE_FILES}
	${SOIL_SOURCE_FILES}
)
target_link_libraries(
	srl
	${OPENGL_LIBRARY}
	${FREETYPE_LIBRARY}
	# ${RUBY_LIBRARY}
)

if( NOT SRL_HOMEMADE_EXT )
	find_package(GLEW)
	target_link_libraries(srl ${GLEW_LIBRARY})
endif( NOT SRL_HOMEMADE_EXT )



add_executable(
	sample/srlTest
	${CMAKE_CURRENT_LIST_DIR}/sample/main.cpp
)

target_link_libraries(
	sample/srlTest
	srl
)