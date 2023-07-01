///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:49)

#ifndef GAME_CLIENT_TESTING_GAME_CLIENT_SUITE_GAME_CLIENT_HELPER_TESTING_H
#define GAME_CLIENT_TESTING_GAME_CLIENT_SUITE_GAME_CLIENT_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace GameClientTesting
{
    class GameClientHelperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GameClientHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit GameClientHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // GAME_CLIENT_TESTING_GAME_CLIENT_SUITE_GAME_CLIENT_HELPER_TESTING_H
