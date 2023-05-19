///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 13:40)

#include "Network/NetworkExport.h"

#include "BufferReceiveStream.h"
#include "MessageEventManager.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "Detail/BufferReceiveStreamImpl.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "Detail/SendMessageLevelImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Network::BufferReceiveStream::BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
    : impl{ messageBuffer, parserStrategy, encryptedCompressionStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferReceiveStream)

void Network::BufferReceiveStream::OnEvent(int64_t socketId, MessageEventManager& messageEventManager)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketId, messageEventManager);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, BufferReceiveStream, IsFinish, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferReceiveStream, PushBack, MessageBufferSharedPtr, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, BufferReceiveStream)