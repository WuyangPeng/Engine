// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.4 (2020/03/12 11:54)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
    class MultipleMessageTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MultipleMessageTesting);

    private:
        void MainTest();

        void RttiTest();
        void FactoryTest() noexcept;
        void StreamingTest();
        void MessageTest();

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t sm_MessageID{ 6 };
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_TESTING_H