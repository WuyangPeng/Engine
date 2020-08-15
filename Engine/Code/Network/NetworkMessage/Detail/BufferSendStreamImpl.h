// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:20)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Network/NetworkMessage/SendMessageLevel.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BufferSendStreamImpl
	{
	public:
		using ClassType = BufferSendStreamImpl;

	public:
		BufferSendStreamImpl(int bytesTotal, ParserStrategy parserStrategy);

		CLASS_INVARIANT_DECLARE;

		bool Insert(const MessageInterfaceSharedPtr& message);
		void Save(const MessageBufferSharedPtr& messageBuffer);
		void Clear();

		bool IsEmpty() const noexcept;
		int GetCurrentSize() const;

	private:
		SendMessageLevel m_TopLevel;
		ParserStrategy m_ParserStrategy;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H
