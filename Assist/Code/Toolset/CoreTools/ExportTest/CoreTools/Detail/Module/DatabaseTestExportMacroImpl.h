///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 15:01)

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
        int count;
    };
}

#endif  // EXPORT_TEST_DATABASE_TEST_EXPORT_MACRO_IMPL_H