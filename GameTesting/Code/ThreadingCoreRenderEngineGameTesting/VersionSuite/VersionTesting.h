///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏测试版本：0.8.0.11 (2022/07/19 15:41)

#ifndef THREADING_CORE_RENDER_ENGINE_GAME_TESTING_VERSION_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_GAME_TESTING_VERSION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace ThreadingCoreRenderEngineGame
{
    class VersionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VersionTesting;
        using ParentType = UnitTest;

    public:
        explicit VersionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_GAME_TESTING_VERSION_TESTING_H