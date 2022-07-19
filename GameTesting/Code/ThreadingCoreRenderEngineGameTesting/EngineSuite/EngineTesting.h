///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ���԰汾��0.8.0.11 (2022/07/19 15:42)

#ifndef THREADING_CORE_RENDER_ENGINE_GAME_TESTING_ENGINE_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_GAME_TESTING_ENGINE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/Application/EngineTestingName.h"

namespace ThreadingCoreRenderEngineGame
{
    class EngineTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EngineTesting;
        using ParentType = UnitTest;

    public:
        explicit EngineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using String = System::String;
        using EngineTestingName = Framework::EngineTestingName;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        [[nodiscard]] bool EngineTest();
        [[nodiscard]] bool ExecuteEngineTesting(int select);
        void ExecuteSelectEngineTesting(const String& engineeringName);

    private:
        EngineTestingName m_EngineTestingName;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_GAME_TESTING_ENGINE_TESTING_H