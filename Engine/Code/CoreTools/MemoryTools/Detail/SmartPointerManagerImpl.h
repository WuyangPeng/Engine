// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE SmartPointerManagerImpl
	{
	public:
		using ClassType = SmartPointerManagerImpl;

	public:
		SmartPointerManagerImpl();

		CLASS_INVARIANT_DECLARE;

		int CopyIncreaseReference(const void* data);
		int IncreaseReference(const void* data);
		int DecreaseReference(const void* data);

		// 用于判断this指针是否为SmartPointerManageImpl创建
		bool IsSmartPointer(const void* data) const;

	private:
		bool IsNullPtr(const void* data) const;

	private:
		using ReferenceContainer = std::map<const void*, int>;

	private:
		// map键（const void*）是共享对象的地址。map值（int）是引用的数目。
		ReferenceContainer m_ReferenceContainer;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H
