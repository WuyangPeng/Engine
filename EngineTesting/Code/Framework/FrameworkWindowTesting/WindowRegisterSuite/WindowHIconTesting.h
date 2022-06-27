///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 13:57)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <map>

namespace Framework
{
    class WindowHIconTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowHIconTesting;
        using ParentType = UnitTest;
        using TChar = System::TChar;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowHIconTesting(const OStreamShared& stream, HInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ConstructorTest();
        void CreateTest();

    private:
        using HIconContainer = std::map<int, const TChar*>;

    private:
        HInstance instance;
        HIconContainer container;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H