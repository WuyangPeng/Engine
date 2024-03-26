/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:50)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_MACRO_H

#include "ResourceManager/ResourceManagerDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(ResourceManager, ResourceManagerTestExportMacroImpl, RESOURCE_MANAGER_DEFAULT_DECLARE);
RESOURCE_MANAGER_EXPORT(ResourceManagerTestExportMacroImpl, NON_COPY);
RESOURCE_MANAGER_EXPORT_UNIQUE_PTR(ResourceManagerTestExportMacro);

namespace ResourceManager
{
    class RESOURCE_MANAGER_DEFAULT_DECLARE ResourceManagerTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ResourceManagerTestExportMacro);

    public:
        explicit ResourceManagerTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_MACRO_H