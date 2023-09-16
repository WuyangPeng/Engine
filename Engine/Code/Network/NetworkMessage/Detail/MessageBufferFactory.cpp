///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:32)

#include "Network/NetworkExport.h"

#include "MessageArrayBufferDetail.h"
#include "MessageBufferFactory.h"
#include "MessageVectorBuffer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"

Network::MessageBufferFactory::MessageBufferFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageBufferFactory)

Network::MessageBufferFactory::ImplTypePtr Network::MessageBufferFactory::Create(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy)
{
    if (constexpr auto maxCount = (System::EnumCastUnderlying(BuffBlockSize::Size512K) << 2);
        maxCount < count)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("分配的缓冲区大小过大！"s))
    }

    switch (buffBlockSize)
    {
        case BuffBlockSize::Size256:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size256>>(parserStrategy);
        case BuffBlockSize::Size512:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size512>>(parserStrategy);
        case BuffBlockSize::Size1024:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size1024>>(parserStrategy);
        case BuffBlockSize::Size2048:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size2048>>(parserStrategy);
        case BuffBlockSize::Size4096:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size4096>>(parserStrategy);
        case BuffBlockSize::Size8K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size8K>>(parserStrategy);
        case BuffBlockSize::Size16K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size16K>>(parserStrategy);
        case BuffBlockSize::Size32K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size32K>>(parserStrategy);
        case BuffBlockSize::Size64K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size64K>>(parserStrategy);
        case BuffBlockSize::Size128K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size128K>>(parserStrategy);
        case BuffBlockSize::Size256K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size256K>>(parserStrategy);
        case BuffBlockSize::Size512K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size512K>>(parserStrategy);
        case BuffBlockSize::Automatic:
            return std::make_shared<MessageVectorBuffer>(count, parserStrategy);
        default:
            break;
    }

    return std::make_shared<MessageVectorBuffer>(count, parserStrategy);
}
