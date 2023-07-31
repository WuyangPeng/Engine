///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:21)

#ifndef EXPORT_TEST_DATABASE_DELAY_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_DATABASE_DELAY_COPY_UNSHARED_MACRO_IMPL_H

#include "Database/DatabaseDll.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseDelayCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = DatabaseDelayCopyUnsharedMacroImpl;

    public:
        explicit DatabaseDelayCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_DATABASE_DELAY_COPY_UNSHARED_MACRO_IMPL_H