///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:33)

#ifndef EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_COPY_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(CoreTools, CoreToolsTestExportCopyMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
CORE_TOOLS_COPY_EXPORT(CoreToolsTestExportCopyMacro, CoreToolsTestExportCopyMacroImpl, COPY_UNSHARED);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CoreToolsTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CoreToolsTestExportCopyMacro);

    public:
        explicit CoreToolsTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_COPY_MACRO_H