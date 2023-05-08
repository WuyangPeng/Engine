///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:36)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_CAST_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_CAST_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MultipleMessageCastTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MultipleMessageCastTesting;
        using ParentType = UnitTest;

    public:
        explicit MultipleMessageCastTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void CastTest() noexcept;
        void ParameterCastTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_CAST_TESTING_H