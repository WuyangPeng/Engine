// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <map>
#include <vector>

namespace CoreTools
{
	class ObjectRegisterImpl
	{
	public:
		using ClassType = ObjectRegisterImpl;

	public:
		ObjectRegisterImpl();

		CLASS_INVARIANT_DECLARE;

		uint64_t GetUniqueID(const ConstObjectInterfaceSmartPointer& smartPointer) const;
		int GetOrderedSize() const;
		const ConstObjectInterfaceSmartPointer& operator [](int smartPointer) const;

		uint64_t RegisterRoot(const ConstObjectInterfaceSmartPointer& smartPointer);

	private:
		using RegisterAssociatedContainer = std::map<ConstObjectInterfaceSmartPointer, uint64_t>;
		using RegisterSequentialContainer = std::vector<ConstObjectInterfaceSmartPointer>;

	private:
		uint64_t GetOriginalUniqueID(const ConstObjectInterfaceSmartPointer& smartPointer) const;

	private:
		// 存储objects，对顶层对象使用图的深度优先遍历。
		RegisterAssociatedContainer m_Registered;
		RegisterSequentialContainer m_Ordered;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
