/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:31)

#ifndef EXPORT_TEST_DATABASE_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_DATABASE_DELAY_COPY_UNSHARED_MACRO_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

DATABASE_DELAY_COPY_UNSHARED_EXPORT_IMPL(DatabaseDelayCopyUnsharedMacro, DatabaseDelayCopyUnsharedMacroImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DatabaseDelayCopyUnsharedMacro);

    public:
        explicit DatabaseDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_DELAY_COPY_UNSHARED_MACRO_H