///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:07)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HCURSOR_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HCURSOR_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace Framework
{
    class WindowHCursorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowHCursorTesting;
        using ParentType = UnitTest;
        using TChar = System::TChar;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowHCursorTesting(const OStreamShared& stream, HInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ConstructorTest();
        void CreateTest();

    private:
        using HCursorContainer = std::map<int, const TChar*>;

    private:
        HInstance instance;
        HCursorContainer container;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HCURSOR_TESTING_H