// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:28)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h" 

NETWORK_EXPORT_SHARED_PTR(BufferSendStreamImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE BufferSendStream
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(BufferSendStream);

	public:
		BufferSendStream(int bytesTotal, ParserStrategy parserStrategy);

		CLASS_INVARIANT_DECLARE;

		bool Insert(const MessageInterfaceSharedPtr& message);
		void Save(const MessageBufferSharedPtr& messageBuffer);
		void Clear();

		bool IsEmpty() const noexcept;
		int GetCurrentSize() const;

	private:
		IMPL_TYPE_DECLARE(BufferSendStream);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
