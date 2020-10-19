//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/19 13:14)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SmartPointerManagerImpl final
    {
    public:
        using ClassType = SmartPointerManagerImpl;

    public:
        SmartPointerManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int CopyIncreaseReference(const void* data);
        [[nodiscard]] int IncreaseReference(const void* data);
        [[nodiscard]] int DecreaseReference(const void* data);

        // �����ж�thisָ���Ƿ�ΪSmartPointerManageImpl����
        [[nodiscard]] bool IsSmartPointer(const void* data) const;

    private:
        [[nodiscard]] bool IsNullPtr(const void* data) const noexcept;

    private:
        using ReferenceContainer = std::map<const void*, int>;

    private:
        // map����const void*���ǹ������ĵ�ַ��mapֵ��int�������õ���Ŀ��
        ReferenceContainer m_ReferenceContainer;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H
