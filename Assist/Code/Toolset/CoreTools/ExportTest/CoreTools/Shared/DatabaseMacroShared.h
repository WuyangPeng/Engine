/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:55)

#ifndef EXPORT_TEST_DATABASE_MACRO_SHARED_H
#define EXPORT_TEST_DATABASE_MACRO_SHARED_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/SharedExportMacro.h"

DATABASE_SHARED_EXPORT_IMPL(DatabaseMacroSharedImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(DatabaseMacroShared);

    public:
        explicit DatabaseMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_MACRO_SHARED_H