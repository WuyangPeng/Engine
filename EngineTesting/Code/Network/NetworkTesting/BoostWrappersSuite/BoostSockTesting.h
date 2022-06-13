///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 17:02)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class BoostSockTesting : public SingletonTesting
    {
    public:
        using ClassType = BoostSockTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostSockTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void BoostServerThread();
        void DoBoostServerThread();

        void AddOffset() noexcept;
        void ClearOffset() noexcept;
        NODISCARD int GetOffset() const noexcept;
        NODISCARD int GetIncrease() const noexcept;
        NODISCARD int GetMessageID() const noexcept;
        NODISCARD int GetRealOffset() const noexcept;
        NODISCARD int GetRealPort() const noexcept;

    private:
        int increase;
        int messageID;
        int offset;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H