///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:54)

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