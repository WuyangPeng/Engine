/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:18)

#ifndef SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_W_PARAM_TESTING_H
#define SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_W_PARAM_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    /// SystemWindowsTesting有其他windows函数的测试。
    class WindowsCreateWParamTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsCreateWParamTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsCreateWParamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr WindowsLParam minValue{ 0 };
        static constexpr WindowsLParam maxValue{ 2048 };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WParamTest();

    private:
        std::default_random_engine generator;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_W_PARAM_TESTING_H