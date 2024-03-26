/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:55)

#ifndef EXPORT_TEST_SCRIPT_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_SCRIPT_PERFORMANCE_UNSHARED_MACRO_H

#include "Script/ScriptDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

SCRIPT_PERFORMANCE_UNSHARED_EXPORT_IMPL(ScriptPerformanceUnsharedMacroImpl);

namespace Script
{
    class SCRIPT_DEFAULT_DECLARE ScriptPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ScriptPerformanceUnsharedMacro);

    public:
        explicit ScriptPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SCRIPT_PERFORMANCE_UNSHARED_MACRO_H