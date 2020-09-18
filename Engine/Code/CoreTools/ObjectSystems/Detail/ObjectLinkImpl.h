// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:32)

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

		ObjectInterfaceSharedPtr GetObjectPtr(uint64_t uniqueID);
		int GetOrderedSize() const;
		ObjectInterfaceSharedPtr& operator [](int index);

		void Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& ptr);

		void Sort();

	private:
		using LinkAssociatedContainer = std::map<uint64_t, ObjectInterfaceSharedPtr>;
		using LinkSequentialContainer = std::vector<ObjectInterfaceSharedPtr>;

	private:
		// �洢ͼ�μ��ع����еĶ������
		LinkAssociatedContainer m_Linked;
		LinkSequentialContainer m_Ordered;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
