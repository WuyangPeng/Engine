///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:19)

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