/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:14)

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
        CreateWindowTestingBase(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD static String GetWindowsName();
        NODISCARD String GetWindowsClassName();
        NODISCARD WindowsHWnd CreateWindowTest(const String& className);

    private:
        WindowsHInstance instance;
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_CREATE_WINDOW_TESTING_BASE_H