///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:40)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_COPY_UNSHARED_MACRO_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = ResourceManagerCopyUnsharedMacroImpl;

    public:
        explicit ResourceManagerCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_COPY_UNSHARED_MACRO_IMPL_H