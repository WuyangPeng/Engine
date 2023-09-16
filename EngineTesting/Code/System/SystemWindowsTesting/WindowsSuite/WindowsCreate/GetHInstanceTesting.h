///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:19)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_H_INSTANCE_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_H_INSTANCE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetHInstanceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetHInstanceTesting;
        using ParentType = UnitTest;

    public:
        GetHInstanceTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetHInstanceTest();

    private:
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_H_INSTANCE_TESTING_H