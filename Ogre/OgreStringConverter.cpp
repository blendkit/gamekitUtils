/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2014 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#include <ut/utString.h>
#include "OgreStringConverter.h"
#include <string>       // std::string
#include <iostream>
#include <sstream>

using namespace std;

namespace Ogre {

typedef std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > _StringStreamBase;
typedef _StringStreamBase StringStream;
typedef StringStream stringstream;

#ifdef __ANDROID__
	String StringConverter::msDefaultStringLocale = "";
#else
	String StringConverter::msDefaultStringLocale = "C";
#endif

    std::locale StringConverter::msLocale = std::locale(msDefaultStringLocale.c_str());
    bool StringConverter::msUseLocale = false;

    //-----------------------------------------------------------------------
    String StringConverter::toString(Real val, unsigned short precision, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.precision(precision);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;

        return stream.str();
    }
#if OGRE_DOUBLE_PRECISION == 1
    //-----------------------------------------------------------------------
    String StringConverter::toString(float val, unsigned short precision,
                                     unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.precision(precision);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
#else
    //-----------------------------------------------------------------------
    String StringConverter::toString(double val, unsigned short precision,
                                     unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.precision(precision);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
#endif
    //-----------------------------------------------------------------------
    String StringConverter::toString(int val, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
    //-----------------------------------------------------------------------
#if OGRE_PLATFORM != OGRE_PLATFORM_NACL &&  ( OGRE_ARCH_TYPE == OGRE_ARCHITECTURE_64 || OGRE_PLATFORM == OGRE_PLATFORM_APPLE || OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS )
    String StringConverter::toString(unsigned int val, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
    //-----------------------------------------------------------------------
    String StringConverter::toString(size_t val, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
#if OGRE_COMPILER == OGRE_COMPILER_MSVC || defined(__MINGW32__)
    //-----------------------------------------------------------------------
    String StringConverter::toString(unsigned long val, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }

#endif
    //-----------------------------------------------------------------------
#else
    //-----------------------------------------------------------------------
    String StringConverter::toString(unsigned long val, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
    //-----------------------------------------------------------------------
#endif
    String StringConverter::toString(long val, 
        unsigned short width, char fill, std::ios::fmtflags flags)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream.width(width);
        stream.fill(fill);
        if (flags)
            stream.setf(flags);
        stream << val;
        return stream.str();
    }
    //-----------------------------------------------------------------------
    String StringConverter::toString(const Vector2& val)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream << val.x << " " << val.y;
        return stream.str();
    }
    //-----------------------------------------------------------------------
    String StringConverter::toString(const Vector3& val)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream << val.x << " " << val.y << " " << val.z;
        return stream.str();
    }
    //-----------------------------------------------------------------------
    String StringConverter::toString(const Vector4& val)
    {
        StringStream stream;
        if (msUseLocale)
            stream.imbue(msLocale);
        stream << val.x << " " << val.y << " " << val.z << " " << val.w;
        return stream.str();
    }
    //-----------------------------------------------------------------------
    String StringConverter::toString(bool val, bool yesNo)
    {
        if (val)
        {
            if (yesNo)
            {
                return "yes";
            }
            else
            {
                return "true";
            }
        }
        else
            if (yesNo)
            {
                return "no";
            }
            else
            {
                return "false";
            }
    }
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    Real StringConverter::parseReal(const String& val, Real defaultValue)
    {
        // Use iStringStream for direct correspondence with toString
        StringStream str(val);
        if (msUseLocale)
            str.imbue(msLocale);
        Real ret = defaultValue;
        if( !(str >> ret) )
            return defaultValue;

        return ret;
    }
    //-----------------------------------------------------------------------
    int StringConverter::parseInt(const String& val, int defaultValue)
    {
        // Use iStringStream for direct correspondence with toString
        StringStream str(val);
        if (msUseLocale)
            str.imbue(msLocale);
        int ret = defaultValue;
        if( !(str >> ret) )
            return defaultValue;

        return ret;
    }
    //-----------------------------------------------------------------------
    unsigned int StringConverter::parseUnsignedInt(const String& val, unsigned int defaultValue)
    {
        // Use iStringStream for direct correspondence with toString
        StringStream str(val);
        if (msUseLocale)
            str.imbue(msLocale);
        unsigned int ret = defaultValue;
        if( !(str >> ret) )
            return defaultValue;

        return ret;
    }
    //-----------------------------------------------------------------------
    long StringConverter::parseLong(const String& val, long defaultValue)
    {
        // Use iStringStream for direct correspondence with toString
        StringStream str(val);
        if (msUseLocale)
            str.imbue(msLocale);
        long ret = defaultValue;
        if( !(str >> ret) )
            return defaultValue;

        return ret;
    }
    //-----------------------------------------------------------------------
    unsigned long StringConverter::parseUnsignedLong(const String& val, unsigned long defaultValue)
    {
        // Use iStringStream for direct correspondence with toString
        StringStream str(val);
        if (msUseLocale)
            str.imbue(msLocale);
        unsigned long ret = defaultValue;
        if( !(str >> ret) )
            return defaultValue;

        return ret;
    }

    //-----------------------------------------------------------------------
    bool StringConverter::parseBool(const String& val, bool defaultValue)
    {
        //FIXME Returns both parsed value and error in same value - ambiguous.
        // Suggested alternatives: implement exception handling or make either
        // error or parsed value a parameter.
        if ((utStringUtils::startsWith(val, "true") || utStringUtils::startsWith(val, "yes")
             || utStringUtils::startsWith(val, "1") ||  utStringUtils::startsWith(val, "on")))
            return true;
        else if ((utStringUtils::startsWith(val, "false") || utStringUtils::startsWith(val, "no")
                  || utStringUtils::startsWith(val, "0") ||  utStringUtils::startsWith(val, "off")))
            return false;
        else
            return defaultValue;
    }
    //-----------------------------------------------------------------------
    Vector2 StringConverter::parseVector2(const String& val, const Vector2& defaultValue)
    {
    	utStringArray vec;
        // Split on space
        utStringUtils::split(vec,val," ");

        if (vec.size() != 2)
        {
            return defaultValue;
        }
        else
        {
            return Vector2(parseReal(vec[0], defaultValue.x), parseReal(vec[1], defaultValue.y));
        }
    }
    //-----------------------------------------------------------------------
    Vector3 StringConverter::parseVector3(const String& val, const Vector3& defaultValue)
    {

    	utStringArray vec;
        // Split on space
        utStringUtils::split(vec,val," ");

        if (vec.size() != 3)
        {
            return defaultValue;
        }
        else
        {
            return Vector3(parseReal(vec[0], defaultValue.x),
                           parseReal(vec[1], defaultValue.y),
                           parseReal(vec[2], defaultValue.z));
        }
    }
    //-----------------------------------------------------------------------
    Vector4 StringConverter::parseVector4(const String& val, const Vector4& defaultValue)
    {
    	utStringArray vec;
        // Split on space
        utStringUtils::split(vec,val," ");

        if (vec.size() != 4)
        {
            return defaultValue;
        }
        else
        {
            return Vector4(parseReal(vec[0], defaultValue.x),
                           parseReal(vec[1], defaultValue.y),
                           parseReal(vec[2], defaultValue.z),
                           parseReal(vec[3], defaultValue.w));
        }
    }
    //-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
}


