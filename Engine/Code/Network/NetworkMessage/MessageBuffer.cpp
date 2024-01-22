/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:22)

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

int Network::MessageBuffer::GetCurrentReadIndex() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetCurrentReadIndex();
}

int Network::MessageBuffer::GetRemainingReadCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetRemainingReadCount();
}

void Network::MessageBuffer::ClearCurrentReadIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->ClearCurrentReadIndex();
}

void Network::MessageBuffer::AddCurrentReadIndex(int stepping)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AddCurrentReadIndex(stepping);
}

int Network::MessageBuffer::GetCurrentWriteIndex() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetCurrentWriteIndex();
}

int Network::MessageBuffer::GetRemainingWriteCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetRemainingWriteCount();
}

void Network::MessageBuffer::ClearCurrentWriteIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->ClearCurrentWriteIndex();
}

void Network::MessageBuffer::AddCurrentWriteIndex(int stepping)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AddCurrentWriteIndex(stepping);
}

const char* Network::MessageBuffer::GetCurrentReadBufferedPtr() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetCurrentReadBufferedPtr();
}

char* Network::MessageBuffer::GetCurrentReadBufferedPtr()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->GetCurrentReadBufferedPtr();
}

const char* Network::MessageBuffer::GetCurrentWriteBufferedPtr() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetCurrentWriteBufferedPtr();
}

char* Network::MessageBuffer::GetCurrentWriteBufferedPtr()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->GetCurrentWriteBufferedPtr();
}

const char* Network::MessageBuffer::GetInitialBufferedPtr() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetInitialBufferedPtr();
}

char* Network::MessageBuffer::GetInitialBufferedPtr()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->GetInitialBufferedPtr();
}

int Network::MessageBuffer::GetReceiveCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetReceiveCount();
}

void Network::MessageBuffer::SetReceiveCount(int receiveCount)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->SetReceiveCount(receiveCount);
}

void Network::MessageBuffer::DecreaseReceiveCount(int receiveCount)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->DecreaseReceiveCount(receiveCount);
}

void Network::MessageBuffer::SetMessageHeadReceiveCount()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->SetMessageHeadReceiveCount();
}

void Network::MessageBuffer::SetMessageContentReceiveCount()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->SetMessageContentReceiveCount();
}

int Network::MessageBuffer::GetMessageLength() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMessageLength();
}

bool Network::MessageBuffer::IsMessageReceiveEnd() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsMessageReceiveEnd();
}

void Network::MessageBuffer::CheckingMessageHeadSize()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->CheckingMessageHeadSize();
}

void Network::MessageBuffer::CheckingMessageContentSize()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->CheckingMessageContentSize();
}

Network::ParserStrategy Network::MessageBuffer::GetParserStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetParserStrategy();
}

int Network::MessageBuffer::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetSize();
}

void Network::MessageBuffer::ClearCurrentIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->ClearCurrentIndex();
}

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
