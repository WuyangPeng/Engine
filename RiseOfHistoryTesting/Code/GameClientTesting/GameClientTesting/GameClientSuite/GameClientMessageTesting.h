///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 18:10)

#ifndef GAME_CLIENT_TESTING_GAME_CLIENT_SUITE_GAME_CLIENT_MESSAGE_TESTING_H
#define GAME_CLIENT_TESTING_GAME_CLIENT_SUITE_GAME_CLIENT_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace GameClientTesting
{
    class GameClientMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GameClientMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit GameClientMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // GAME_CLIENT_TESTING_GAME_CLIENT_SUITE_GAME_CLIENT_MESSAGE_TESTING_H
