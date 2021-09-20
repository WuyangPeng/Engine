//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:15)

#include "Network/NetworkExport.h"

#include "SendMessageLevel.h"
#include "Detail/SendMessageLevelImpl.h"

#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;

Network::SendMessageLevel::SendMessageLevel(int messageMaxSize)
    : impl{ messageMaxSize }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendMessageLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SendMessageLevel, operator[], int, const Network::ConstMessageInterfaceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, SendMessageLevel, Insert, MessageInterfaceSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SendMessageLevel, operator[], int, Network::MessageInterfaceSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendMessageLevel, GetRemainingSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendMessageLevel, GetCurrentSize, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, Clear, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, SendMessageLevel)