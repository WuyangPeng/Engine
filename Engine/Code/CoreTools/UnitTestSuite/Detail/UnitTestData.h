/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:20)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestData final
    {
    public:
        using ClassType = UnitTestData;

    public:
        UnitTestData() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetPassedNumber() const noexcept;
        NODISCARD int GetFailedNumber() const noexcept;
        NODISCARD int GetErrorNumber() const noexcept;
        NODISCARD bool IsEmpty() const noexcept;

        void AddPassedNumber() noexcept;
        void AddFailedNumber();
        void AddErrorNumber();
        void ClearData() noexcept;

    private:
        int pass;
        int fail;
        int error;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H
