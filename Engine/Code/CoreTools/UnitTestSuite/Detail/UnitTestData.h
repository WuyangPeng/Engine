///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 18:54)

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
        void AddFailedNumber() noexcept;
        void AddErrorNumber() noexcept;
        void ClearData() noexcept;

    private:
        int pass;
        int fail;
        int error;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H
