// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:16)

#include "Network/NetworkExport.h"

#include "BufferSendStreamImpl.h" 
#include "System/Time/DeltaTime.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/VersionInformation/Version.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::make_shared;

Network::BufferSendStreamImpl
	::BufferSendStreamImpl(int bytesTotal, ParserStrategy parserStrategy)
	:m_TopLevel{ bytesTotal - MessageInterface::GetMessageHeadSize() }, m_ParserStrategy{ parserStrategy }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStreamImpl)

bool Network::BufferSendStreamImpl
	::Insert(const MessageInterfaceSharedPtr& message)
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

void Network::BufferSendStreamImpl
	::Save(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	auto currentSize = m_TopLevel.GetCurrentSize();
	auto messageLength = currentSize + MessageInterface::GetMessageHeadSize();

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
		THROW_EXCEPTION(SYSTEM_TEXT("»º³åÇø´óÐ¡²»×ã£¡"));
	}
}

void Network::BufferSendStreamImpl
	::Clear()
{
	NETWORK_CLASS_IS_VALID_9;

	m_TopLevel.Clear();
}

bool Network::BufferSendStreamImpl
	::IsEmpty() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	if (m_TopLevel.GetCurrentSize() == 0)
		return true;
	else
		return false;
}

int Network::BufferSendStreamImpl
	::GetCurrentSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_TopLevel.GetCurrentSize() + MessageInterface::GetMessageHeadSize();
}


