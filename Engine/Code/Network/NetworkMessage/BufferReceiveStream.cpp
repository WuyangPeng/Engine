//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:57)

#include "Network/NetworkExport.h"

#include "BufferReceiveStream.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "SocketManager.h"
#include "Detail/BufferReceiveStreamImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using std::make_shared;
using std::string;

Network::BufferReceiveStream::BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy)
    : m_Impl{ make_shared<ImplType>(messageBuffer, parserStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, BufferReceiveStream)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, BufferReceiveStream)

void Network::BufferReceiveStream::OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->OnEvent(socketID, socketManager);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, BufferReceiveStream, IsFinish, bool)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, BufferReceiveStream, PushBack, MessageBufferSharedPtr, void)
