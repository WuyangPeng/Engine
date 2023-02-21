///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:54)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = ResourceManagerPerformanceUnsharedMacroImpl;

    public:
        explicit ResourceManagerPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_PERFORMANCE_UNSHARED_MACRO_IMPL_H