// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 16:19)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_H

#include "CoreTools/CoreToolsDll.h"

#include "PropertyBase.h"

namespace CoreTools
{
	// 需要通过宏TCRE_DECLARE_PROPERTY来声明属性
	template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
	class Property : PropertyBase<ID, T>
	{
	public:
		using ParentType = PropertyBase<ID, T>;
		using ClassType = Property<ID, T, V, R, FS, FG>;

	public:
		Property();
		explicit Property(V value);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		ClassType& operator=(R value);
		operator R() const;

	public:
		V m_Value;
	};
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_H