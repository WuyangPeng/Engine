///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 11:36)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_MESSAGE_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_MESSAGE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TelegramMessageManagerTesting final : public UnitTest
    {
    public:
        using ClassType = TelegramMessageManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit TelegramMessageManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void AllEventTest();
        void SpecifiedEventTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_MESSAGE_MANAGER_TESTING_H