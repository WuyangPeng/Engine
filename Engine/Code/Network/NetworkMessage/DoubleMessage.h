///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 14:09)

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(DoubleMessage);

        NODISCARD int32_t GetMessageID() const override;
        NODISCARD int32_t GetSubMessageID() const override;

    private:
        static constexpr auto sm_MessageBytes = 32LL;
        static constexpr auto sm_MaxMessageID = (1LL << sm_MessageBytes) - 1LL;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(DoubleMessage);
}

#endif  // NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H
