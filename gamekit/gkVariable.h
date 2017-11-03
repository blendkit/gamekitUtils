/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Charlie C.

    Contributor(s): none yet.
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
#ifndef _gkVariable_h_
#define _gkVariable_h_


#include "gkMiniMath.h"
#include "gkValue.h"
#include <ut/utString.h>
#include <ut/utTypes.h>


class gkVariable
{
public:
	typedef utArray<float> FloatArray;
	typedef utArray<int> IntArray;
	typedef utArray<bool> BoolArray;

	typedef enum PropertyTypes
	{
		VAR_NULL = 0,
		VAR_BOOL,
		VAR_REAL,
		VAR_INT,
		VAR_VEC2,
		VAR_VEC3,
		VAR_VEC4,
		VAR_QUAT,
		VAR_MAT3,
		VAR_MAT4,
		VAR_STRING,
		VAR_COLOR,
		VAR_FLOATARRAY,
		VAR_INTARRAY,
		VAR_BOOLARRAY
	} PropertyTypes;



	gkVariable();
	gkVariable(const utString& n, bool dbg);

	explicit gkVariable(bool v, const utString& name = utStringUtils::BLANK);
	explicit gkVariable(int v, const utString& name = utStringUtils::BLANK);
	explicit gkVariable(float v, const utString& name = utStringUtils::BLANK);
	explicit gkVariable(const utString& v, const utString& name = utStringUtils::BLANK);
	explicit gkVariable(const gkVector2& v, const utString& name = utStringUtils::BLANK);
	explicit gkVariable(const gkVector3& v, const utString& name = utStringUtils::BLANK);
	explicit gkVariable(const gkVector4& v, const utString& name = utStringUtils::BLANK);



	~gkVariable();

	gkVariable* clone(void);

	GK_INLINE int   getType(void) const           { return m_type;}
	GK_INLINE void  setDebug(bool v)              { m_debug = v;}
	GK_INLINE void  setReadOnly(bool v)           { m_lock = v;}
	GK_INLINE bool  isReadOnly(void)              { return m_lock;}
	GK_INLINE bool  isDebug(void) const           { return m_debug; }
	GK_INLINE const utString& getName(void) const { return m_name; }

	void setValue(int type, const utString& v);

	utString toString() { return m_value.toString(); }

	void setValue(bool v);
	void setValue(int v);
	void setValue(float v);
	void setValue(const utString& v);
	void setValue(const gkVector2& v);
	void setValue(const gkVector3& v);
	void setValue(const gkVector4& v);
//	void setValue(const gkVariable& v);



	bool         getValueBool(void) const;
	int          getValueInt(void) const;
	float     getValueReal(void) const;
	utString     getValueString(void) const;
	gkVector2    getValueVector2(void) const;
	gkVector3    getValueVector3(void) const;
	gkVector4    getValueVector4(void) const;

	template<typename T>
	T get() const
	{
		return m_value.get<T>();
	}

	bool operator < (const gkVariable& o) const;
	bool operator > (const gkVariable& o) const;

	bool operator <= (const gkVariable& o) const;
	bool operator >= (const gkVariable& o) const;

	bool operator == (const gkVariable& o) const;
	bool operator != (const gkVariable& o) const;


	void assign(const utString& o);
	void add(const utString& o);
	void inverse(const utString& o);
	void toggle(const utString& o);

	void assign(const gkVariable& o);
	void add(const gkVariable& o);
	void inverse(const gkVariable& o);
	void toggle(const gkVariable& o);

	bool hasInverse(void);

	void makeDefault(void);
	void reset(void);


private:

	gkValue         m_value;
	gkValue         m_default;
	int          m_type;
	utString     m_name;
	bool         m_debug, m_lock;
};


#endif//_gkVariable_h_
