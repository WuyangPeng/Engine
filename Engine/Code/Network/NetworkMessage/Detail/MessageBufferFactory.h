///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 10:43)

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

        NODISCARD static ImplTypePtr Create(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H
