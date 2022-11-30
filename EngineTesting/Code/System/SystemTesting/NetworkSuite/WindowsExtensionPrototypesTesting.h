///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/03 21:59)

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