///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:35)

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
