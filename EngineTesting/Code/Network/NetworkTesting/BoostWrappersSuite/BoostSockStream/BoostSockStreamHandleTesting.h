///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:47)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSockStreamHandleTesting final : public BoostSockStreamTesting
    {
    public:
        using ClassType = BoostSockStreamHandleTesting;
        using ParentType = BoostSockStreamTesting;

    public:
        explicit BoostSockStreamHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H