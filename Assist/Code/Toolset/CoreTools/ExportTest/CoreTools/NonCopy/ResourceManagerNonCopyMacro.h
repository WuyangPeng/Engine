///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 0:04)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_NON_COPY_MACRO_H
#define EXPORT_TEST_RESOURCE_MANAGER_NON_COPY_MACRO_H

#include "ResourceManager/ResourceManagerDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

RESOURCE_MANAGER_NON_COPY_EXPORT_IMPL(ResourceManagerNonCopyMacroImpl);

namespace ResourceManager
{
    class RESOURCE_MANAGER_DEFAULT_DECLARE ResourceManagerNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ResourceManagerNonCopyMacro);

    public:
        explicit ResourceManagerNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_NON_COPY_MACRO_H