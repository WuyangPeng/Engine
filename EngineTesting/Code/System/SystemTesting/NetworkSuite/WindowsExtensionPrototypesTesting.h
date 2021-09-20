///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 14:50)

#ifndef SYSTEM_SECURITY_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H
#define SYSTEM_SECURITY_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsExtensionPrototypesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsExtensionPrototypesTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsExtensionPrototypesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WinSockLastErrorTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H