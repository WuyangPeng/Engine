// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:37)

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
		// �洢objects���Զ������ʹ��ͼ��������ȱ�����
		RegisterAssociatedContainer m_Registered;
		RegisterSequentialContainer m_Ordered;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
