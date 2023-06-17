///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:49)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowCreateHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowCreateHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowCreateHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
