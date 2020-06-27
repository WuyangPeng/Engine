// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:21)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H

#include "Network/NetworkDll.h" 

#include "MessageBufferImpl.h"
#include "System/Helper/EnumCast.h"

#include <array>

namespace Network
{
	template<BuffBlockSize buffBlockSize>
	class MessageArrayBuffer : public MessageBufferImpl
	{
	public:
		using ClassType = MessageArrayBuffer<buffBlockSize>;
		using ParentType = MessageBufferImpl;

	public:
		explicit MessageArrayBuffer(ParserStrategy parserStrategy);
		virtual ~MessageArrayBuffer();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual const char* GetInitialBufferedPtr() const override;
		virtual char* GetInitialBufferedPtr() override;

		virtual ImplPtr Clone() const override;

		virtual BuffBlockSize GetBuffBlockSize() const override;
		virtual int GetSize() const override;

		virtual ImplPtr Expansion(int count) const override;

	private:
		std::array<char, System::EnumCastUnderlying(buffBlockSize)> m_Buffer;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H
