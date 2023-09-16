///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:45)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H

#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class BoostSockTesting : public SingletonTesting
    {
    public:
        using ClassType = BoostSockTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostSockTesting(const OStreamShared& stream, int increase = 2500);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void BoostServerThread();
        void DoBoostServerThread();

        void AddOffset() noexcept;
        void ClearOffset() noexcept;
        NODISCARD int GetOffset() const noexcept;
        NODISCARD int GetIncrease() const noexcept;
        NODISCARD int GetMessageId() const noexcept;
        NODISCARD int GetRealOffset() const noexcept;
        NODISCARD int GetRealPort() const noexcept;

    private:
        int increase;
        int messageId;
        int offset;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H