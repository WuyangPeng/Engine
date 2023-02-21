///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/12 16:02)

#ifndef CORE_TOOLS_HELPER_SUITE_LOG_ENGINE_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_LOG_ENGINE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogEngineMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LogEngineMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit LogEngineMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void EngineLogTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_LOG_ENGINE_MACRO_TESTING_H