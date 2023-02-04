///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 19:45)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_WINDOW_TESTING_BASE_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_WINDOW_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateWindowTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateWindowTestingBase;
        using ParentType = UnitTest;

    public:
        explicit CreateWindowTestingBase(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD static String GetWindowsName();
        NODISCARD String GetWindowsClassName();
        NODISCARD WindowsHWnd CreateWindowTest(const String& className);

    private:
        WindowsHInstance instance;
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_WINDOW_TESTING_BASE_H