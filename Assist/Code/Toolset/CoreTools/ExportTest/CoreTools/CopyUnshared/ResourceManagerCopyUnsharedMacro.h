///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 14:10)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_RESOURCE_MANAGER_COPY_UNSHARED_MACRO_H

#include "ResourceManager/ResourceManagerDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RESOURCE_MANAGER_COPY_UNSHARED_EXPORT_IMPL(ResourceManagerCopyUnsharedMacro, ResourceManagerCopyUnsharedMacroImpl);

namespace ResourceManager
{
    class RESOURCE_MANAGER_DEFAULT_DECLARE ResourceManagerCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ResourceManagerCopyUnsharedMacro);

    public:
        explicit ResourceManagerCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_COPY_UNSHARED_MACRO_H