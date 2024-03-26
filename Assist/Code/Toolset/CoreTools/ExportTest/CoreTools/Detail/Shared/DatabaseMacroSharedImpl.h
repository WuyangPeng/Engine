/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:44)

#ifndef EXPORT_TEST_DATABASE_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_DATABASE_MACRO_SHARED_IMPL_H

#include "Database/DatabaseDll.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseMacroSharedImpl final
    {
    public:
        using ClassType = DatabaseMacroSharedImpl;

    public:
        explicit DatabaseMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_DATABASE_MACRO_SHARED_IMPL_H