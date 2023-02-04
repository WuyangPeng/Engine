///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 19:45)

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