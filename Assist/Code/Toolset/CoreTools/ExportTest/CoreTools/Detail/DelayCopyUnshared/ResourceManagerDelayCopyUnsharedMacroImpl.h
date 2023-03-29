///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:14)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_DELAY_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_DELAY_COPY_UNSHARED_MACRO_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerDelayCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = ResourceManagerDelayCopyUnsharedMacroImpl;

    public:
        explicit ResourceManagerDelayCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_DELAY_COPY_UNSHARED_MACRO_IMPL_H