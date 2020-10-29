//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:35)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageBufferFactory final
    {
    public:
        using ClassType = MessageBufferFactory;
        using ImplType = MessageBufferImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        MessageBufferFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static const ImplTypePtr Create(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H
