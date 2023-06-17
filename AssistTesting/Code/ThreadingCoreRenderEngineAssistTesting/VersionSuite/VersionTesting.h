///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.9.0.12 (2023/06/15 19:17)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_VERSION_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_VERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace ThreadingCoreRenderEngineAssist
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

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_VERSION_TESTING_H