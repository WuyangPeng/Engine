///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:42)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_DOUBLE_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_DOUBLE_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
    class StringDoubleMessageTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StringDoubleMessageTesting);

    private:
        void MainTest();

        void RttiTest();
        void FactoryTest();
        void StreamingTest();
        void MessageTest();

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
        static constexpr int64_t subMessageID{ 4 };
        static constexpr auto fullMessageID = (messageID << 32ull) + subMessageID;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_DOUBLE_MESSAGE_TESTING_H