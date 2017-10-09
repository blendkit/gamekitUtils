cmake_minimum_required(VERSION 2.6)

project(gkUtils)

set (SOURCE 
	gkMiniMath.h
	gkMiniMath.cpp
	gkValue.h
	gkVariable.cpp
	gkVariable.h
	utCommon.h
	utMemoryPool.h
	utRandom.cpp
	utRandom.h
	utScript.cpp
	utScript.h
	utSingleton.h
	utStreams.cpp
	utStreams.h
	utString.cpp
	utString.h
	utTypes.h

	Ogre/OgreStringConverter.cpp
	Ogre/OgreStringConverter.h
)



include_directories(${OGREKIT_ZLIB_INCLUDE})

add_library(${PROJECT_NAME} ${SOURCE})
