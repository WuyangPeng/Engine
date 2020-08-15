// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:32)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <set>
#include <vector>

namespace CoreTools
{
	class InTopLevelImpl
	{
	public:
		using ClassType = InTopLevelImpl;

	public:
		InTopLevelImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		bool IsTopLevel(uint64_t uniqueID) const;
		int GetTopLevelSize() const;
		ConstObjectInterfaceSmartPointer operator [](int index) const;
		ObjectInterfaceSmartPointer& operator [](int index);

		// 对顶层的对象进行保存。
		void Insert(const ObjectInterfaceSmartPointer& objectPtr);

	private:
		using ObjectContainer = std::vector<ObjectInterfaceSmartPointer>;
		using UniqueIDContainer = std::set<uint64_t>;

	private:
		// 顶层对象的流。
		ObjectContainer m_TopLevel;
		UniqueIDContainer m_UniqueID;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H
