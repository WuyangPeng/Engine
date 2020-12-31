//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:14)

#include "Network/NetworkExport.h"

#include "ReceiveMessageLevel.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::ReceiveMessageLevel::ReceiveMessageLevel()
    : m_Impl{ make_shared<ImplType>() }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, ReceiveMessageLevel)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, ReceiveMessageLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ReceiveMessageLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ReceiveMessageLevel, operator[], int, const Network::ConstMessageInterfaceSharedPtr)

void Network::ReceiveMessageLevel::Insert(const MessageInterfaceSharedPtr& message)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Insert(message);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ReceiveMessageLevel, begin, Network::ReceiveMessageLevel::MessageContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ReceiveMessageLevel, end, Network::ReceiveMessageLevel::MessageContainerConstIter)
