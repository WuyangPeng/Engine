///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:59)

#ifndef EXPORT_TEST_DATABASE_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_DATABASE_PERFORMANCE_UNSHARED_MACRO_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(DatabasePerformanceUnsharedMacroImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabasePerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(DatabasePerformanceUnsharedMacro);

    public:
        explicit DatabasePerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_PERFORMANCE_UNSHARED_MACRO_H