/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:43)

#ifndef EXPORT_TEST_DATABASE_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_DATABASE_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "Database/DatabaseDll.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabasePerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = DatabasePerformanceUnsharedMacroImpl;

    public:
        explicit DatabasePerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_DATABASE_PERFORMANCE_UNSHARED_MACRO_IMPL_H