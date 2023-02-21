///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 16:20)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_LESS_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_LESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TelegramLessTesting : public UnitTest
    {
    public:
        using ClassType = TelegramLessTesting;
        using ParentType = UnitTest;

    public:
        explicit TelegramLessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void LessTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_LESS_TESTING_H