///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:20)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_SYSTEM_WINDOW_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_SYSTEM_WINDOW_TESTING_H

#include "CreateWindowTestingBase.h"

namespace System
{
    class CreateSystemWindowTesting final : public CreateWindowTestingBase
    {
    public:
        using ClassType = CreateSystemWindowTesting;
        using ParentType = CreateWindowTestingBase;

    public:
        CreateSystemWindowTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateSystemWindowTest();

        void ResultTest(WindowsHWnd systemWindow, const String& className);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_SYSTEM_WINDOW_TESTING_H