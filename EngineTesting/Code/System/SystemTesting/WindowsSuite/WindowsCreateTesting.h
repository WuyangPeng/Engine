///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/06 16:23)

#ifndef SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_TESTING_H
#define SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsCreateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsCreateTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsCreateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LParamTest();
        void WParamTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_WINDOWS_CREATE_TESTING_H