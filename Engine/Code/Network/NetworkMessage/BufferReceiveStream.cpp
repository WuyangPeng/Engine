// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:32)

#include "Network/NetworkExport.h"

#include "BufferReceiveStream.h"
#include "SocketManager.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "Detail/BufferReceiveStreamImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

using std::string;

Network::BufferReceiveStream
	::BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy)
	:m_Impl{ make_shared<ImplType>(messageBuffer,parserStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, BufferReceiveStream)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, BufferReceiveStream) 

void Network::BufferReceiveStream
	::OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OnEvent(socketID, socketManager);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, BufferReceiveStream, IsFinish, bool)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferReceiveStream, PushBack, MessageBufferSharedPtr, void)
