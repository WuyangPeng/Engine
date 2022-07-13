///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:09)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_RESOURCE_MANAGER_DELAY_COPY_UNSHARED_MACRO_H

#include "ResourceManager/ResourceManagerDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

RESOURCE_MANAGER_DELAY_COPY_UNSHARED_EXPORT_IMPL(ResourceManagerDelayCopyUnsharedMacro, ResourceManagerDelayCopyUnsharedMacroImpl);

namespace ResourceManager
{
    class RESOURCE_MANAGER_DEFAULT_DECLARE ResourceManagerDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ResourceManagerDelayCopyUnsharedMacro);

    public:
        explicit ResourceManagerDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_DELAY_COPY_UNSHARED_MACRO_H