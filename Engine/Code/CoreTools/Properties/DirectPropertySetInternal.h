// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 16:17)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	template<typename Value, // 实际属性值类型
			 typename Reference, // 引用类型
			 typename Container> // 封闭类	
	class DirectPropertySetInternal : private boost::noncopyable
	{
	public:
		using ValueType = Value;
		using ReferenceType = Reference;
		using ContainerType = Container;
		using ClassType = DirectPropertySetInternal<ValueType, ReferenceType, ContainerType>;

		CLASS_INVARIANT_DECLARE;

	private:
		explicit DirectPropertySetInternal(ReferenceType value);
		operator ReferenceType () const;

		TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

	public:
		ClassType& operator=(ReferenceType value);

	private:
		ValueType m_Value;
	};
}

#endif // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H