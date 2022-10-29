///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:51)

#ifndef SYSTEM_CONSOLE_SUITE_SET_CONSOLE_HANDLE_SCREEN_BUFFER_INFO_TESTING_H
#define SYSTEM_CONSOLE_SUITE_SET_CONSOLE_HANDLE_SCREEN_BUFFER_INFO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SetConsoleHandleScreenBufferInfoTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetConsoleHandleScreenBufferInfoTesting;
        using ParentType = UnitTest;

    public:
        explicit SetConsoleHandleScreenBufferInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetConsoleScreenBufferInfoTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_SET_CONSOLE_HANDLE_SCREEN_BUFFER_INFO_TESTING_H