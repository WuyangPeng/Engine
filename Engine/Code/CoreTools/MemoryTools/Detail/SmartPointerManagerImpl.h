// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:40)

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

		// �����ж�thisָ���Ƿ�ΪSmartPointerManageImpl����
		bool IsSmartPointer(const void* data) const;

	private:
		bool IsNullPtr(const void* data) const;

	private:
		using ReferenceContainer = std::map<const void*, int>;

	private:
		// map����const void*���ǹ������ĵ�ַ��mapֵ��int�������õ���Ŀ��
		ReferenceContainer m_ReferenceContainer;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H
