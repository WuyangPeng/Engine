///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:48)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_SYNCHRONIZE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostFixedSockStreamSynchronizeTesting final : public BoostSockStreamTesting
    {
    public:
        using ClassType = BoostFixedSockStreamSynchronizeTesting;
        using ParentType = BoostSockStreamTesting;

    public:
        explicit BoostFixedSockStreamSynchronizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_SYNCHRONIZE_TESTING_H