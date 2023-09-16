///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:40)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MARK_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MARK_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
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

        void SYSTEM_CALL_BACK CallBackTest() noexcept;
        void SYSTEM_WINAPI WinApiTest() noexcept;
        void ParameterMarkTest() noexcept;
        void DoParameterMarkTest(SYSTEM_IN int in, SYSTEM_IN_OPT int* inOpt, SYSTEM_OUT int& out, SYSTEM_OUT_OPT int* outOpt, SYSTEM_IN_OUT int& inOut, SYSTEM_IN_OUT_OPT int* inOutOpt) noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MARK_TESTING_H
