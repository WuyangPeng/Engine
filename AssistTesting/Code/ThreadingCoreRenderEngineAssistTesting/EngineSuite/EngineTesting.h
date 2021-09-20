///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 16:12)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_ENGINE_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_ENGINE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/Application/EngineTestingName.h"

namespace ThreadingCoreRenderEngineAssist
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

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_ENGINE_TESTING_H