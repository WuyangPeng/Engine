/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:49)

#ifndef EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(CoreTools, CoreToolsTestExportMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
CORE_TOOLS_EXPORT(CoreToolsTestExportMacroImpl, NON_COPY);
CORE_TOOLS_EXPORT_UNIQUE_PTR(CoreToolsTestExportMacro);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CoreToolsTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(CoreToolsTestExportMacro);

    public:
        explicit CoreToolsTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_MACRO_H