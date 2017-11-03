cmake_minimum_required(VERSION 2.6)

project(gkUtils)

set (SOURCE 
	gamekit/gkMiniMath.h
	gamekit/gkMiniMath.cpp
	gamekit/gkValue.h
	gamekit/gkVariable.cpp
	gamekit/gkVariable.h
	
	ut/utCommon.h
	ut/utMemoryPool.h
	ut/utRandom.cpp
	ut/utRandom.h
	ut/utScript.cpp
	ut/utScript.h
	ut/utSingleton.h
	ut/utStreams.cpp
	ut/utStreams.h
	ut/utString.cpp
	ut/utString.h
	ut/utTypes.h

	Ogre/OgreStringConverter.cpp
	Ogre/OgreStringConverter.h
	
	bullet/btAlignedAllocator.cpp
	bullet/btAlignedAllocator.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_library(${PROJECT_NAME} ${SOURCE})
