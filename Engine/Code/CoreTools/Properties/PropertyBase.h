// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 16:20)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h" 

namespace CoreTools
{
	// 需要通过宏TCRE_DEFINE_PROPERTY定义m_Offset
	template<typename ID, typename T>
	class PropertyBase
	{
	public:
		using ClassType = PropertyBase<ID, T>;

	public:
		virtual ~PropertyBase();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	protected:
		T* Holder();
		const T* Holder() const;

	private:
		static const ptrdiff_t m_Offset;
	};
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H