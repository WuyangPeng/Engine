///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/23 11:13)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OutputDebugStringTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OutputDebugStringTesting;
        using ParentType = UnitTest;

    public:
        explicit OutputDebugStringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OutputCharToDebugTest() noexcept;
        void OutputWCharToDebugTest() noexcept;
        void OutputTCharToDebugTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H