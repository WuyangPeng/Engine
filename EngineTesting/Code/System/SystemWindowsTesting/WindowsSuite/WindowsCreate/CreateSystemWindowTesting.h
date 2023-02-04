///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 19:45)

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
        explicit CreateSystemWindowTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateSystemWindowTest();

        void ResultTest(WindowsHWnd systemWindow, const String& className);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_SYSTEM_WINDOW_TESTING_H