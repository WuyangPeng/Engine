///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/30 16:11)

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
        void DoRunUnitTest() final;
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
