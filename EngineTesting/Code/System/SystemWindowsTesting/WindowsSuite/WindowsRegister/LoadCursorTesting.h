///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 21:05)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_LOAD_CURSOR_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_LOAD_CURSOR_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LoadCursorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadCursorTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadCursorTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadCursorTest();

    private:
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_LOAD_CURSOR_TESTING_H