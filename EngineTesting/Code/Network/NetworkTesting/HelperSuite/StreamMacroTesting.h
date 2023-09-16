///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:11)

#ifndef NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H
#define NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class StreamMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StreamMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit StreamMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void TestMessageTest();
    };
}

#endif  // NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H