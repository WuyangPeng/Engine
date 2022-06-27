///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 10:55)

#ifndef FRAMEWORK_HELPER_SUITE_MACINTOSH_CALL_BACK_INTERFACE_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MACINTOSH_CALL_BACK_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class MacintoshCallBackInterfaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MacintoshCallBackInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit MacintoshCallBackInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MACINTOSH_CALL_BACK_INTERFACE_TESTING_H