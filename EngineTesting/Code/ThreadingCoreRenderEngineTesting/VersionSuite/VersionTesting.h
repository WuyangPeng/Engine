///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.0 (2021/02/19 14:22)

#ifndef THREADING_CORE_RENDER_ENGINE_TESTING_VERSION_TESTING_H
#define THREADING_CORE_RENDER_ENGINE_TESTING_VERSION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

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
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_TESTING_VERSION_TESTING_H