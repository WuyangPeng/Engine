///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 19:30)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_ERROR_TESTING_H
#define CORE_TOOLS_EXCEPTION_SUITE_ERROR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ErrorTesting final : public UnitTest
    {
    public:
        using ClassType = ErrorTesting;
        using ParentType = UnitTest;

    public:
        explicit ErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void NormalErrorTest();
        void WindowsErrorTest();
        void OpenFileErrorTest();
        void ComErrorTest();
        void ThrowExceptionTest();
        void ThrowLastExceptionTest();
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_ERROR_TESTING_H
