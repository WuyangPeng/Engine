/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/16 19:55)

#ifndef THREADING_CORE_RENDER_ENGINE_TESTING_ENGINE_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_TESTING_ENGINE_TESTING_H

#include "CoreTools/UnitTestSuite//UnitTest.h"
#include "Framework/Application/EngineTestingName.h"

namespace ThreadingCoreRenderEngine
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
        void DoRunUnitTest() override;

        void MainTest();

        NODISCARD bool EngineTest();
        NODISCARD bool ExecuteEngineTesting(int select);
        void ExecuteSelectEngineTesting(const String& engineeringName);

    private:
        EngineTestingName engineTestingName;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_TESTING_ENGINE_TESTING_H