// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:32)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <map>
#include <vector>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ObjectLinkImpl
	{
	public:
		using ClassType = ObjectLinkImpl;

	public:
		ObjectLinkImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		ObjectInterfaceSmartPointer GetObjectPtr(uint64_t uniqueID);
		int GetOrderedSize() const;
		ObjectInterfaceSmartPointer& operator [](int index);

		void Insert(uint64_t uniqueID, const ObjectInterfaceSmartPointer& ptr);

		void Sort();

	private:
		using LinkAssociatedContainer = std::map<uint64_t, ObjectInterfaceSmartPointer>;
		using LinkSequentialContainer = std::vector<ObjectInterfaceSmartPointer>;

	private:
		// 存储图形加载过程中的顶层对象。
		LinkAssociatedContainer m_Linked;
		LinkSequentialContainer m_Ordered;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
