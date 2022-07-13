///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 22:19)

#ifndef EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_IMPL_H

#include "Database/DatabaseDll.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseTestExportMacroImpl final
    {
    public:
        using ClassType = DatabaseTestExportMacroImpl;

    public:
        explicit DatabaseTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_IMPL_H