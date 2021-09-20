//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 13:57)

#include "Network/NetworkExport.h"

#include "BufferReceiveStream.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "SocketManager.h"
#include "Detail/BufferReceiveStreamImpl.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "Detail/SendMessageLevelImpl.h"
#include "System/MemoryTools/MemoryHelper.h"

#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
using std::make_shared;
using std::string;

Network::BufferReceiveStream::BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy)
    : impl{ messageBuffer, parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferReceiveStream)

void Network::BufferReceiveStream::OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->OnEvent(socketID, socketManager);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, BufferReceiveStream, IsFinish, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferReceiveStream, PushBack, MessageBufferSharedPtr, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, BufferReceiveStream)