///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:00)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_MACRO_SHARED_H
#define EXPORT_TEST_RESOURCE_MANAGER_MACRO_SHARED_H

#include "ResourceManager/ResourceManagerDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

RESOURCE_MANAGER_SHARED_EXPORT_IMPL(ResourceManagerMacroSharedImpl);

namespace ResourceManager
{
    class RESOURCE_MANAGER_DEFAULT_DECLARE ResourceManagerMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ResourceManagerMacroShared);

    public:
        explicit ResourceManagerMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_MACRO_SHARED_H