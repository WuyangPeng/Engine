///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:17)

#ifndef FRAMEWORK_HELPER_SUITE_LINUX_CALL_BACK_INTERFACE_TESTING_H
#define FRAMEWORK_HELPER_SUITE_LINUX_CALL_BACK_INTERFACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class LinuxCallBackInterfaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LinuxCallBackInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit LinuxCallBackInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_LINUX_CALL_BACK_INTERFACE_TESTING_H