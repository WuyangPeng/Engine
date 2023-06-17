///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:23)

#ifndef FRAMEWORK_HELPER_SUITE_CONSOLE_CALL_BACK_INTERFACE_TESTING_H
#define FRAMEWORK_HELPER_SUITE_CONSOLE_CALL_BACK_INTERFACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class ConsoleCallBackInterfaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleCallBackInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleCallBackInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_CONSOLE_CALL_BACK_INTERFACE_TESTING_H