//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:56)

#include "Network/NetworkExport.h"

#include "BufferSendStreamImpl.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

using std::make_shared;

Network::BufferSendStreamImpl::BufferSendStreamImpl(int bytesTotal, ParserStrategy parserStrategy)
    : m_TopLevel{ bytesTotal - MessageInterface::GetMessageHeadSize() }, m_ParserStrategy{ parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStreamImpl)

bool Network::BufferSendStreamImpl::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (message->GetStreamingSize() <= m_TopLevel.GetRemainingSize())
    {
        m_TopLevel.Insert(message);

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

    const auto currentSize = m_TopLevel.GetCurrentSize();
    const auto messageLength = currentSize + MessageInterface::GetMessageHeadSize();

    if (messageLength <= messageBuffer->GetSize())
    {
        MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(messageBuffer) };

        messageTarget->Write(messageLength);
        messageTarget->Write(MESSAGE_MANAGER_SINGLETON.GetFullVersion());
        messageTarget->Write(System::GetTimeInMicroseconds());

        for (auto i = 0; i < m_TopLevel.GetTopLevelSize(); ++i)
        {
            m_TopLevel[i]->Save(messageTarget);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s));
    }
}

void Network::BufferSendStreamImpl::Clear()
{
    NETWORK_CLASS_IS_VALID_9;

    m_TopLevel.Clear();
}

bool Network::BufferSendStreamImpl::IsEmpty() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (m_TopLevel.GetCurrentSize() == 0)
        return true;
    else
        return false;
}

int Network::BufferSendStreamImpl::GetCurrentSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.GetCurrentSize() + MessageInterface::GetMessageHeadSize();
}


