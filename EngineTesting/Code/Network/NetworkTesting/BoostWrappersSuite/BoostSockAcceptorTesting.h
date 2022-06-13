///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 16:31)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H

#include "BoostSockTesting.h"

namespace Network
{
    class BoostSockAcceptorTesting : public BoostSockTesting
    {
    public:
        using ClassType = BoostSockAcceptorTesting;
        using ParentType = BoostSockTesting;

    public:
        explicit BoostSockAcceptorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using TestingType = SockAcceptor;
        using TestingTypeSharedPtr = std::shared_ptr<SockAcceptor>;

    protected:
        void ClientThread();
        void DoClientThread();

        NODISCARD static constexpr int GetConnectTime() noexcept
        {
            return connectTime;
        }

        NODISCARD static constexpr int GetAsynchronousAcceptTime() noexcept
        {
            return asynchronousAcceptTime;
        }

        NODISCARD static constexpr int GetSynchronizeAcceptTime() noexcept
        {
            return synchronizeAcceptTime;
        }

    private:
        // Release�汾asynchronousAcceptTimeֵҪ�㹻�󣬷������ʱ�첽�ص���δִ�С�
        static constexpr auto connectTime = 100;
        static constexpr auto synchronizeAcceptTime = 1000;
        static constexpr auto asynchronousAcceptTime = 100000000;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H