///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 16:21)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TelegramTesting : public UnitTest
    {
    public:
        using ClassType = TelegramTesting;
        using ParentType = UnitTest;

    public:
        explicit TelegramTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void TelegramTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H