///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/30 16:08)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TESTING_H
#define CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class GameErrorTesting final : public UnitTest
    {
    public:
        using ClassType = GameErrorTesting;
        using ParentType = UnitTest;

    public:
        explicit GameErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LastErrorTest();
        void ComErrorTest();
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TESTING_H
