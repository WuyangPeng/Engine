/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:15)

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

        void MessageBoxTest() const;

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_MESSAGE_BOX_TESTING_H