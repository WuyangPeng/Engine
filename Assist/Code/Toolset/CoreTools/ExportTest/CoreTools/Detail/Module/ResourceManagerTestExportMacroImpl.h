///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:56)

#ifndef EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_MACRO_IMPL_H

#include "ResourceManager/ResourceManagerDll.h"

namespace ResourceManager
{
    class ResourceManagerTestExportMacroImpl final
    {
    public:
        using ClassType = ResourceManagerTestExportMacroImpl;

    public:
        explicit ResourceManagerTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_RESOURCE_MANAGER_TEST_EXPORT_MACRO_IMPL_H