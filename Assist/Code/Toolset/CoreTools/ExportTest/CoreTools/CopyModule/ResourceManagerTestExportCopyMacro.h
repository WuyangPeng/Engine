///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:54)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_COPY_MACRO_H

#include "ResourceManager/ResourceManagerDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(ResourceManager, ResourceManagerTestExportCopyMacroImpl, RESOURCE_MANAGER_DEFAULT_DECLARE);
RESOURCE_MANAGER_COPY_EXPORT(ResourceManagerTestExportCopyMacro, ResourceManagerTestExportCopyMacroImpl, COPY_UNSHARED);

namespace ResourceManager
{
    class RESOURCE_MANAGER_DEFAULT_DECLARE ResourceManagerTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ResourceManagerTestExportCopyMacro);

    public:
        explicit ResourceManagerTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_COPY_MACRO_H