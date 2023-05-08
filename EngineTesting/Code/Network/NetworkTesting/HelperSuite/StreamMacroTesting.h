///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 15:28)

#ifndef NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H
#define NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class StreamMacroTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = StreamMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit StreamMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void TestMessageTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H