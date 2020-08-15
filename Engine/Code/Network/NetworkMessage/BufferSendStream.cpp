// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:33)

#include "Network/NetworkExport.h"

#include "BufferSendStream.h"
#include "MessageBuffer.h"
#include "MessageManager.h"
#include "MessageTargetDetail.h"
#include "Detail/BufferSendStreamImpl.h"  
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::make_shared;

Network::BufferSendStream
	::BufferSendStream(int bytesTotal, ParserStrategy parserStrategy)
	:m_Impl{ make_shared<ImplType>(bytesTotal,parserStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, BufferSendStream)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, BufferSendStream) 

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferSendStream, Insert, MessageInterfaceSharedPtr, bool)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferSendStream, Save, MessageBufferSharedPtr, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Network, BufferSendStream, Clear, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, BufferSendStream, IsEmpty, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, BufferSendStream, GetCurrentSize, int)


