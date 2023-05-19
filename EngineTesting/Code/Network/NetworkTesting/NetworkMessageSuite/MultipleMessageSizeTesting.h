///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 09:20)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_SIZE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MultipleMessageSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MultipleMessageSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit MultipleMessageSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void NineSizeTest() noexcept;
        void FiveSizeTest() noexcept;
        void TwoSizeTest() noexcept;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_SIZE_TESTING_H