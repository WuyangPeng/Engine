///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 23:54)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_MACRO_SHARED_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerMacroSharedImpl final
    {
    public:
        using ClassType = ResourceManagerMacroSharedImpl;

    public:
        explicit ResourceManagerMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_MACRO_SHARED_IMPL_H