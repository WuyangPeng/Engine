///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:54)

#ifndef EXPORT_TEST_DATABASE_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_DATABASE_TEST_EXPORT_COPY_MACRO_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Database, DatabaseTestExportCopyMacroImpl, DATABASE_DEFAULT_DECLARE);
DATABASE_COPY_EXPORT(DatabaseTestExportCopyMacro, DatabaseTestExportCopyMacroImpl, DELAY_COPY_UNSHARED);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseTestExportCopyMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DatabaseTestExportCopyMacro);

    public:
        explicit DatabaseTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_TEST_EXPORT_COPY_MACRO_H