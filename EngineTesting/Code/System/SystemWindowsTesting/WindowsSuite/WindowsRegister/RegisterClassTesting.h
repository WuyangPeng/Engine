///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 19:44)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_CLASS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_CLASS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class RegisterClassTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RegisterClassTesting;
        using ParentType = UnitTest;

    public:
        explicit RegisterClassTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RegisterClassTest();

    private:
        WindowsHInstance instance;
        int count;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_CLASS_TESTING_H