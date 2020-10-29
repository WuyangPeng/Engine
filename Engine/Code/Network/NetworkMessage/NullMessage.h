//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 10:16)

#ifndef NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NullMessage final : public MessageInterface
    {
    public:
        using ClassType = NullMessage;
        using ParentType = MessageInterface;

    public:
        explicit NullMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(NullMessage);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(NullMessage);
}

#endif  // NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
