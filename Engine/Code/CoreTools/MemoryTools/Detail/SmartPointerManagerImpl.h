//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/19 13:14)

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

        // 用于判断this指针是否为SmartPointerManageImpl创建
        [[nodiscard]] bool IsSmartPointer(const void* data) const;

    private:
        [[nodiscard]] bool IsNullPtr(const void* data) const noexcept;

    private:
        using ReferenceContainer = std::map<const void*, int>;

    private:
        // map键（const void*）是共享对象的地址。map值（int）是引用的数目。
        ReferenceContainer m_ReferenceContainer;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_IMPL_H
