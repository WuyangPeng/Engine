///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:20)

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