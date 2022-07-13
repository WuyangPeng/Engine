///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:06)

#ifndef EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

EXPORT_CONST_SHARED_PTR(CoreTools, ExportConstImplMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_CONST_IMPL(ExportConstImplMacroImpl, CORE_TOOLS, PERFORMANCE_UNSHARED);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportConstImplMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ExportConstImplMacro);

    public:
        explicit ExportConstImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_H