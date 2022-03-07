///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 11:08)

#include "Network/NetworkExport.h"

#include "ReceiveMessageLevel.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, ReceiveMessageLevel)

Network::ReceiveMessageLevel Network::ReceiveMessageLevel::Create()
{
    return ReceiveMessageLevel{ CoreTools::DisableNotThrow::Disable };
}

Network::ReceiveMessageLevel::ReceiveMessageLevel(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReceiveMessageLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ReceiveMessageLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ReceiveMessageLevel, operator[], int, Network::ConstMessageInterfaceSharedPtr)

void Network::ReceiveMessageLevel::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(message);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ReceiveMessageLevel, begin, Network::ReceiveMessageLevel::MessageContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ReceiveMessageLevel, end, Network::ReceiveMessageLevel::MessageContainerConstIter)
