//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 11:30)

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

        [[nodiscard]] int GetPassedNumber() const noexcept;
        [[nodiscard]] int GetFailedNumber() const noexcept;
        [[nodiscard]] int GetErrorNumber() const noexcept;
        [[nodiscard]] bool IsEmpty() const noexcept;

        void AddPassedNumber() noexcept;
        void AddFailedNumber() noexcept;
        void AddErrorNumber() noexcept;
        void ClearData() noexcept;

    private:
        int m_Pass;
        int m_Fail;
        int m_Error;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H
