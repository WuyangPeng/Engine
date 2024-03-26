/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:14)

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