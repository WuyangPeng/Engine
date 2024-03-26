/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:27)

#ifndef EXPORT_TEST_DATABASE_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_DATABASE_COPY_UNSHARED_MACRO_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

DATABASE_COPY_UNSHARED_EXPORT_IMPL(DatabaseCopyUnsharedMacro, DatabaseCopyUnsharedMacroImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(DatabaseCopyUnsharedMacro);

    public:
        explicit DatabaseCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_COPY_UNSHARED_MACRO_H