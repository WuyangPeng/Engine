// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:25)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H

#include "Network/NetworkDll.h" 

#include "MessageBufferImpl.h"

#include <vector>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageVectorBuffer : public MessageBufferImpl
	{
	public:
		using ClassType = MessageVectorBuffer;
		using ParentType = MessageBufferImpl;

	public:
		MessageVectorBuffer(int count, ParserStrategy parserStrategy);
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		  const char* GetInitialBufferedPtr() const noexcept override;
		  char* GetInitialBufferedPtr() noexcept override;

		  ImplPtr Clone() const override;

		  BuffBlockSize GetBuffBlockSize() const noexcept override;
		  int GetSize() const override;

		  ImplPtr Expansion(int count) const override;

	private:
		void Resize(int count);

	private:
		std::vector<char> m_Buffer;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H
