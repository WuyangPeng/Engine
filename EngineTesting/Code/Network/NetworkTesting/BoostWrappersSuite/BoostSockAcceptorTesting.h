///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:37)

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
        // Release版本asynchronousAcceptTime值要足够大，否则测试时异步回调还未执行。
        static constexpr auto connectTime = 100;
        static constexpr auto synchronizeAcceptTime = 1000;
        static constexpr auto asynchronousAcceptTime = 100000000;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H