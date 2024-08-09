/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 00:10)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_GLOBAL_CONFIG_TESTING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_GLOBAL_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class GlobalConfigTesting final : public UnitTest
    {
    public:
        using ClassType = GlobalConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit GlobalConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GlobalConfigTest();
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_GLOBAL_CONFIG_TESTING_H