///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/19 11:14)

#include "Network/NetworkExport.h"

#include "SendMessageLevel.h"
#include "Detail/SendMessageLevelImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, SendMessageLevel)

Network::SendMessageLevel::SendMessageLevel(int messageMaxSize)
    : impl{ messageMaxSize }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendMessageLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SendMessageLevel, operator[], int, Network::ConstMessageInterfaceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, SendMessageLevel, Insert, MessageInterfaceSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SendMessageLevel, operator[], int, Network::MessageInterfaceSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendMessageLevel, GetRemainingSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, SendMessageLevel, GetCurrentSize, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, Clear, void)
