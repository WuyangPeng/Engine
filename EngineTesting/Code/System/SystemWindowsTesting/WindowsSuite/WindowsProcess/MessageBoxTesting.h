///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:20)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_MESSAGE_BOX_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_MESSAGE_BOX_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MessageBoxTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxTesting;
        using ParentType = UnitTest;

    public:
        MessageBoxTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MessageBoxTest();

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_MESSAGE_BOX_TESTING_H