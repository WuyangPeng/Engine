// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <vector>
#include <set>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE OutTopLevelImpl
	{
	public:
		using ClassType = OutTopLevelImpl;

	public:
		OutTopLevelImpl();

		CLASS_INVARIANT_DECLARE;

		bool IsTopLevel(uint64_t uniqueID) const;
		int GetTopLevelSize() const;
		const ConstObjectInterfaceSmartPointer& operator [](int index) const;

		// �Զ���Ķ�����б��档
		void Insert(const ObjectInterfaceSmartPointer& objectPtr);
		void SetUniqueID(int index, uint64_t uniqueID);

	private:
		using ObjectPtrCollection = std::vector<ObjectInterfaceSmartPointer>;
		using UniqueIDCollection = std::set<uint64_t>;

	private:
		// ������������
		ObjectPtrCollection m_TopLevel;
		UniqueIDCollection m_UniqueID;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H
