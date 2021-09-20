///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:35)

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