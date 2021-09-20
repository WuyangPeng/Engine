///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:56)

#ifndef EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_H

#include "Script/ScriptDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

EXPORT_CONST_SHARED_PTR(Script, ScriptTestExportMacroImpl, SCRIPT_DEFAULT_DECLARE);
SCRIPT_EXPORT(ScriptTestExportMacroImpl, PERFORMANCE_UNSHARED);
SCRIPT_EXPORT_UNIQUE_PTR(ScriptTestExportMacro);

namespace Script
{
    class SCRIPT_DEFAULT_DECLARE ScriptTestExportMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ScriptTestExportMacro);

    public:
        explicit ScriptTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SCRIPT_TEST_EXPORT_MACRO_H