///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 11:10)

#include "Network/NetworkExport.h"

#include "MessageBuffer.h"
#include "Detail/MessageBufferFactory.h"
#include "Detail/MessageBufferImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, MessageBuffer)

Network::MessageBuffer::MessageBuffer(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, buffBlockSize, count, parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBuffer::MessageBuffer(BuffBlockSize buffBlockSize, ParserStrategy parserStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, buffBlockSize, 0, parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBuffer::MessageBuffer(int count, ParserStrategy parserStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, System::UnderlyingCastEnum<BuffBlockSize>(count), count, parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageBuffer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, ClearCurrentIndex, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, GetCurrentReadIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, GetRemainingReadCount, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, ClearCurrentReadIndex, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageBuffer, AddCurrentReadIndex, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, GetCurrentWriteIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetRemainingWriteCount, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, ClearCurrentWriteIndex, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageBuffer, AddCurrentWriteIndex, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetCurrentReadBufferedPtr, const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetCurrentReadBufferedPtr, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetCurrentWriteBufferedPtr, const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetCurrentWriteBufferedPtr, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetInitialBufferedPtr, const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetInitialBufferedPtr, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, MessageBuffer, GetParserStrategy, Network::ParserStrategy)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetReceiveCount, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageBuffer, SetReceiveCount, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, MessageBuffer, DecreaseReceiveCount, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, SetMessageHeadReceiveCount, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, SetMessageContentReceiveCount, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, GetMessageLength, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, IsMessageReceiveEnd, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, CheckingMessageHeadSize, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, MessageBuffer, CheckingMessageContentSize, void)

void Network::MessageBuffer::Read(int itemSize, void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Read(itemSize, data);
}

void Network::MessageBuffer::Read(int itemSize, int itemsNumber, void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Read(itemSize, itemsNumber, data);
}

void Network::MessageBuffer::Write(int itemSize, const void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Write(itemSize, data);
}

void Network::MessageBuffer::Write(int itemSize, int itemsNumber, const void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Write(itemSize, itemsNumber, data);
}

void Network::MessageBuffer::PushBack(const MessageBuffer& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->PushBack(*messageBuffer.impl);
}

Network::MessageBuffer::MessageBufferSharedPtr Network::MessageBuffer::Expansion(int count) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (count <= GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("扩容大小小于原容器大小"s))
    }

    auto messageVectorBuffer = std::make_shared<ClassType>(count, GetParserStrategy());

    messageVectorBuffer->PushBack(*this);
    messageVectorBuffer->AddCurrentReadIndex(GetCurrentReadIndex());
    messageVectorBuffer->SetReceiveCount(GetReceiveCount());

    return messageVectorBuffer;
}

Network::MessageBuffer::MessageBufferSharedPtr Network::MessageBuffer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return std::make_shared<MessageBuffer>(*this);
}
