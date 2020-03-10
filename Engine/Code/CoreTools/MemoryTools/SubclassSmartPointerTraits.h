// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_SMART_POINTER_TRAITS_H
#define CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_SMART_POINTER_TRAITS_H

namespace CoreTools
{
	template <typename SubClass>
	struct SubclassSmartPointerTraits
	{
		using ParentType = typename SubClass::ParentType;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_SMART_POINTER_TRAITS_H
