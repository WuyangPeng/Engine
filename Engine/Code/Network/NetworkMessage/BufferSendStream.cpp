//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 13:57)

#include "Network/NetworkExport.h"

#include "BufferSendStream.h"
#include "MessageBuffer.h"
#include "MessageManager.h"
#include "MessageTargetDetail.h"
#include "Detail/BufferSendStreamImpl.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "Detail/SendMessageLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BufferSendStream::BufferSendStream(int bytesTotal, ParserStrategy parserStrategy)
    : impl{ bytesTotal, parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStream)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferSendStream, Insert, MessageInterfaceSharedPtr, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferSendStream, Save, MessageBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, BufferSendStream, Clear, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, BufferSendStream, IsEmpty, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, BufferSendStream, GetCurrentSize, int)
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, BufferSendStream)