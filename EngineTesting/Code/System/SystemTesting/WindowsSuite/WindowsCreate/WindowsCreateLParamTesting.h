///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 19:01)

#ifndef SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_LPARAM_TESTING_H
#define SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_LPARAM_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class WindowsCreateLParamTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsCreateLParamTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsCreateLParamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr WindowsLParam minValue{ 0 };
        static constexpr WindowsLParam maxValue{ 2048 };

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LParamTest();

    private:
        std::default_random_engine generator;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_LPARAM_TESTING_H