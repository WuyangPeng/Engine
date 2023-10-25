///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:13)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class InitTermTesting final : public UnitTest
    {
    public:
        using ClassType = InitTermTesting;
        using ParentType = UnitTest;

    public:
        explicit InitTermTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTermTest();

        void DoRunUnitTest() override;

        static void Initializer() noexcept;
        static void Terminator() noexcept;

    private:
        static bool initializeCall;
        static bool terminateCall;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H