/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:19)

#include "Network/NetworkExport.h"

#include "BufferSendStreamImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::BufferSendStreamImpl::BufferSendStreamImpl(int bytesTotal, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
    : topLevel{ bytesTotal - MessageInterface::GetMessageHeadSize() }, parserStrategy{ parserStrategy }, encryptedCompressionStrategy{ encryptedCompressionStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStreamImpl)

bool Network::BufferSendStreamImpl::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (message->GetStreamingSize() <= topLevel.GetRemainingSize())
    {
        topLevel.Insert(message);

        return true;
    }
    else
    {
        return false;
    }
}

void Network::BufferSendStreamImpl::Save(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto currentSize = topLevel.GetCurrentSize();

    if (const auto messageLength = currentSize + MessageInterface::GetMessageHeadSize();
        messageLength <= messageBuffer->GetSize())
    {
        MessageTarget messageTarget{ *messageBuffer };

        messageTarget.Write(messageLength);
        messageTarget.Write(MESSAGE_MANAGER_SINGLETON.GetFullVersion());
        messageTarget.Write(System::GetTimeInMicroseconds());

        for (auto i = 0; i < topLevel.GetTopLevelSize(); ++i)
        {
            topLevel[i]->Save(messageTarget);
        }

        EncryptedCompression(messageBuffer);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s))
    }
}

void Network::BufferSendStreamImpl::Clear()
{
    NETWORK_CLASS_IS_VALID_9;

    topLevel.Clear();
}

bool Network::BufferSendStreamImpl::IsEmpty() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (topLevel.GetCurrentSize() == 0)
        return true;
    else
        return false;
}

int Network::BufferSendStreamImpl::GetCurrentSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return topLevel.GetCurrentSize() + MessageInterface::GetMessageHeadSize();
}

void Network::BufferSendStreamImpl::EncryptedCompression(const MessageBufferSharedPtr& messageBuffer) noexcept
{
    System::UnusedFunction(messageBuffer);
}
