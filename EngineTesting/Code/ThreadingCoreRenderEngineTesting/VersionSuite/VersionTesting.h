///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 09:41)

#ifndef THREADING_CORE_RENDER_ENGINE_TESTING_VERSION_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_TESTING_VERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace ThreadingCoreRenderEngine
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
        void DoRunUnitTest() override;

        void MainTest();
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_TESTING_VERSION_TESTING_H