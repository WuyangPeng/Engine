/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:58)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_ENTITY_TESTING_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_ENTITY_TESTING_H

#include "Detail/PlayerEntity.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StateEntityTesting final : public UnitTest
    {
    public:
        using ClassType = StateEntityTesting;
        using ParentType = UnitTest;

    public:
        explicit StateEntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using PlayerEntitySharedPtr = std::shared_ptr<PlayerEntity>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PlayerTest();
        void StateTest(const PlayerEntity& playerEntity);
        NODISCARD static PlayerEntitySharedPtr MakeEntity();

        void EventFunction0Test(PlayerEntity& playerEntity);
        void EventFunction1Test(PlayerEntity& playerEntity);
        void EventFunction2Test(PlayerEntity& playerEntity);
        void EventFunction3Test(PlayerEntity& playerEntity);
        void EventFunction4Test(PlayerEntity& playerEntity);
        void EventFunction5Test(PlayerEntity& playerEntity);
        void EventFunction6Test(PlayerEntity& playerEntity);
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_ENTITY_TESTING_H