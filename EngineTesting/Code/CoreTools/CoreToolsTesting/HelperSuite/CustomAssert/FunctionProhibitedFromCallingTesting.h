/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 00:14)

#ifndef CORE_TOOLS_HELPER_SUITE_FUNCTION_PROHIBITED_FROM_CALLING_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_FUNCTION_PROHIBITED_FROM_CALLING_TESTING_H

#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FunctionProhibitedFromCallingTesting final : public UnitTest
    {
    public:
        using ClassType = FunctionProhibitedFromCallingTesting;
        using ParentType = UnitTest;

    public:
        explicit FunctionProhibitedFromCallingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FunctionProhibitedFromCallingTest() noexcept(gAssert < 4);
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_FUNCTION_PROHIBITED_FROM_CALLING_TESTING_H