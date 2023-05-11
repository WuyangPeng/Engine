///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 19:01)

#ifndef SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_WPARAM_TESTING_H
#define SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_WPARAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <random>

namespace System
{
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
        void DoRunUnitTest() final;
        void MainTest();

        void WParamTest();

    private:
        std::default_random_engine generator;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_WPARAM_TESTING_H