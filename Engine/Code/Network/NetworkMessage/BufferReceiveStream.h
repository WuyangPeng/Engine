// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:27)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h" 

NETWORK_EXPORT_SHARED_PTR(BufferReceiveStreamImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE BufferReceiveStream
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(BufferReceiveStream);

	public:
		explicit BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy);

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(BufferReceiveStream);

		void OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager);

		// 如果读取未完成，需要继续解析
		bool IsFinish() const;

		void PushBack(const MessageBufferSharedPtr& messageBuffer);

	private:
		IMPL_TYPE_DECLARE(BufferReceiveStream);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H
