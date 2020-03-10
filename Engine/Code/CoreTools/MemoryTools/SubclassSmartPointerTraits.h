// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:43)

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
