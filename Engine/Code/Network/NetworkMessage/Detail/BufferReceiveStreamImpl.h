// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:18)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Network/NetworkMessage/ReceiveMessageLevel.h" 
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BufferReceiveStreamImpl
	{
	public:
		using ClassType = BufferReceiveStreamImpl;

	public:
		BufferReceiveStreamImpl(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy);

		BufferReceiveStreamImpl(const BufferReceiveStreamImpl& rhs);
		BufferReceiveStreamImpl& operator=(const BufferReceiveStreamImpl& rhs);
		BufferReceiveStreamImpl(BufferReceiveStreamImpl&& rhs) noexcept;
		BufferReceiveStreamImpl& operator=(BufferReceiveStreamImpl&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		void OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager);

		// 如果读取未完成，需要继续解析
		bool IsFinish() const;

		void PushBack(const MessageBufferSharedPtr& messageBuffer);

	private:
		void AnalysisBuffer(const MessageBufferSharedPtr& messageBuffer);
		void DoAnalysisBuffer(const MessageBufferSharedPtr& messageBuffer);
		void CopyToLastMessageSource();
		void SpliceMessageSource(const MessageBufferSharedPtr& messageBuffer);
		void ReadMessage(const MessageSourceSharedPtr& messageSource, int fullVersion);

	private:
		ReceiveMessageLevel m_TopLevel;
		ParserStrategy m_ParserStrategy;
		MessageBufferSharedPtr m_LastMessageBuffer;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H
