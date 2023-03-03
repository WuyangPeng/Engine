///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.8.0.10 (2022/07/13 13:57)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_ENGINE_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_ENGINE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
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

        NODISCARD bool EngineTest();
        NODISCARD bool ExecuteEngineTesting(int select);
        void ExecuteSelectEngineTesting(const String& engineeringName);

    private:
        EngineTestingName engineTestingName;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_ENGINE_TESTING_H