//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 11:58)

#include "Network/NetworkExport.h"

#include "MessageArrayBufferDetail.h"
#include "MessageBufferFactory.h"
#include "MessageVectorBuffer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"

using std::make_shared;

Network::MessageBufferFactory::MessageBufferFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageBufferFactory)

// static
const Network::MessageBufferFactory::ImplTypePtr Network::MessageBufferFactory::Create(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy)
{
    constexpr auto maxCount = (System::EnumCastUnderlying(BuffBlockSize::Size512K) << 2);
    if (maxCount < count)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Ļ�������С����"s));
    }

    switch (buffBlockSize)
    {
        case Network::BuffBlockSize::Size256:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size256>>(parserStrategy);
        case Network::BuffBlockSize::Size512:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size512>>(parserStrategy);
        case Network::BuffBlockSize::Size1024:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size1024>>(parserStrategy);
        case Network::BuffBlockSize::Size2048:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size2048>>(parserStrategy);
        case Network::BuffBlockSize::Size4096:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size4096>>(parserStrategy);
        case Network::BuffBlockSize::Size8K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size8K>>(parserStrategy);
        case Network::BuffBlockSize::Size16K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size16K>>(parserStrategy);
        case Network::BuffBlockSize::Size32K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size32K>>(parserStrategy);
        case Network::BuffBlockSize::Size64K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size64K>>(parserStrategy);
        case Network::BuffBlockSize::Size128K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size128K>>(parserStrategy);
        case Network::BuffBlockSize::Size256K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size256K>>(parserStrategy);
        case Network::BuffBlockSize::Size512K:
            return std::make_shared<MessageArrayBuffer<BuffBlockSize::Size512K>>(parserStrategy);
        case Network::BuffBlockSize::Automatic:
            return std::make_shared<MessageVectorBuffer>(count, parserStrategy);
        default:
            break;
    }

    return std::make_shared<MessageVectorBuffer>(count, parserStrategy);
}
