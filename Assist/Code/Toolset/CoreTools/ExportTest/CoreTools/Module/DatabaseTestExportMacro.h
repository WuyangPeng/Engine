///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:41)

#ifndef EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

EXPORT_CONST_SHARED_PTR(Database, DatabaseTestExportMacroImpl, DATABASE_DEFAULT_DECLARE);
DATABASE_EXPORT(DatabaseTestExportMacroImpl, PERFORMANCE_UNSHARED);
DATABASE_EXPORT_UNIQUE_PTR(DatabaseTestExportMacro);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseTestExportMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(DatabaseTestExportMacro);

    public:
        explicit DatabaseTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_H