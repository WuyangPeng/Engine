/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:22)

#include "Network/NetworkExport.h"

#include "BufferReceiveStream.h"
#include "MessageEventManager.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "Detail/BufferReceiveStreamImpl.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, BufferReceiveStream)

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

bool Network::BufferReceiveStream::IsFinish() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsFinish();
}

void Network::BufferReceiveStream::PushBack(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->PushBack(messageBuffer);
}
