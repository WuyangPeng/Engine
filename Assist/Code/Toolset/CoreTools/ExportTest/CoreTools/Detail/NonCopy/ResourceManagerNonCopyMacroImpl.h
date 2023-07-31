///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:34)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_NON_COPY_MACRO_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_NON_COPY_MACRO_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerNonCopyMacroImpl final
    {
    public:
        using ClassType = ResourceManagerNonCopyMacroImpl;

    public:
        explicit ResourceManagerNonCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_NON_COPY_MACRO_IMPL_H