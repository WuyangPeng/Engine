// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:37)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NULL_SOCKET_MANAGER_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NULL_SOCKET_MANAGER_H

#include "TestNetworkMessageEvent.h"
#include "Network/NetworkMessage/SocketManager.h"

namespace Network
{
    class NullSocketManager : public SocketManager
    {
    public:
        using ClassType = NullSocketManager;
        using ParentType = SocketManager;
        using CallbackParameters = CoreTools::CallbackParameters;

    public:
        explicit NullSocketManager(int64_t messageID);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool EventFunction(const CallbackParameters& callbackParameters) noexcept override;

        int GetValue() const noexcept;

    private:
        void InitEvent(uint64_t socketID) override;

    private:
        TestNetworkMessageEventSharedPtr m_Event;
        int64_t m_MessageID;
    };

    using NullSocketManagerSharedPtr = std::shared_ptr<NullSocketManager>;
    using ConstNullSocketManagerSharedPtr = std::shared_ptr<const NullSocketManager>;
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NULL_SOCKET_MANAGER_H
