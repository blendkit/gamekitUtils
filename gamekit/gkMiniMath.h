/*
-------------------------------------------------------------------------------
    General Purpose Utility Library, should be kept dependency free.
    Unless the dependency can be compiled along with this library.

    Copyright (c) 2009-2010 Charlie C.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/

#pragma once
#include "utString.h"

class utVector2{
public:
	utVector2(float x,float y) : x(x),y(y){}

	float x,y;

	static utVector2 ZERO;
};

class utVector3{
public:
	utVector3(float x,float y,float z) : x(x),y(y),z(z){}

	float x,y,z;
	static utVector3 ZERO ;
};

class utVector4{
public:
	utVector4(float x,float y,float z,float w) : x(x),y(y),z(z),w(w){}

	float x,y,z,w;
	static utVector4 ZERO;
    inline bool operator==(const utVector4& checkVec )const{
    	return ( x==checkVec.x && y==checkVec.y && z==checkVec.z && w==checkVec.w);
    }

    inline bool operator!=(const utVector4& checkVec )const{
    	return ( x!=checkVec.x || y!=checkVec.y || z!=checkVec.z || w!=checkVec.w);
    }

    inline utVector4 operator+(const utVector4& v )const{
    	return utVector4(x+v.x,y+v.y,z+v.z,w+v.w);
    }

};


typedef utVector2 gkVector2;
typedef utVector3 gkVector3;
typedef utVector4 gkVector4;
typedef utString gkString;
typedef float gkScalar;

#define GK_INLINE inline
