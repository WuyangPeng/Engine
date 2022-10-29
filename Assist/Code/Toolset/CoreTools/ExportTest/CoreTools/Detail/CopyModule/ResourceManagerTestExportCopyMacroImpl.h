///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:44)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerTestExportCopyMacroImpl final
    {
    public:
        using ClassType = ResourceManagerTestExportCopyMacroImpl;

    public:
        explicit ResourceManagerTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_COPY_MACRO_IMPL_H