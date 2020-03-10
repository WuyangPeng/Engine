// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:37)

#include "Network/NetworkExport.h"

#include "SendMessageLevel.h"
#include "Detail/SendMessageLevelImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

Network::SendMessageLevel
	::SendMessageLevel(int messageMaxSize)
	:m_Impl{ make_shared<ImplType>(messageMaxSize) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, SendMessageLevel)
DELAY_COPY_CONSTRUCTION_DEFINE(Network, SendMessageLevel)
DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(Network, SendMessageLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SendMessageLevel, operator[], int, const Network::ConstMessageInterfaceSharedPtr)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Network, SendMessageLevel, Insert, MessageInterfaceSharedPtr, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, SendMessageLevel, operator[], int, Network::MessageInterfaceSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, GetRemainingSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, GetCurrentSize, int)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Network, SendMessageLevel, Clear, void)
