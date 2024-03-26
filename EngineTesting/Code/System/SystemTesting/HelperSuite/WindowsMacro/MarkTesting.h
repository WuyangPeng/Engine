/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 09:57)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MARK_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MARK_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief Windows宏测试
    class MarkTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MarkTesting;
        using ParentType = UnitTest;

    public:
        explicit MarkTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SYSTEM_CALL_BACK CallBackTest() const noexcept;
        void SYSTEM_WIN_API WinApiTest() const noexcept;
        void ParameterMarkTest() const noexcept;
        void DoParameterMarkTest(SYSTEM_IN int in, SYSTEM_IN_OPT int* inOpt, SYSTEM_OUT int& out, SYSTEM_OUT_OPT int* outOpt, SYSTEM_IN_OUT int& inOut, SYSTEM_IN_OUT_OPT int* inOutOpt) const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MARK_TESTING_H
