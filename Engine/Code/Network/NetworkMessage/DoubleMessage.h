// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:28)

#ifndef NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE DoubleMessage : public MessageInterface
    {
    public:
        using ClassType = DoubleMessage;
        using ParentType = MessageInterface;

    public:
        explicit DoubleMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(DoubleMessage);

        int GetMessageID() const override;
        int GetSubMessageID() const override;

    private:
        static constexpr auto sm_MessageBytes = 32LL;
        static constexpr auto sm_MaxMessageID = (1LL << sm_MessageBytes) - 1LL;
    };

    using DoubleMessageSharedPtr = std::shared_ptr<DoubleMessage>;
    using ConstDoubleMessageSharedPtr = std::shared_ptr<const DoubleMessage>;
}

#endif  // NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H
