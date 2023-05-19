///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:51)

#include "Network/NetworkExport.h"

#include "HandleSet.h"
#include "Detail/HandleSetFactory.h"
#include "Detail/HandleSetImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, HandleSet)

Network::HandleSet::HandleSet(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSet)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, SetBit, ACEHandleType, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetMaxSet, int64_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetFdSet, Network::SockFdSet*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, Sync, ACEHandleType, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, IsSet, ACEHandleType, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, ClearBit, ACEHandleType, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetACEHandleSet, const Network::ACEHandleSet&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetFull, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetCount, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, Select, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetCountIsOne, bool)
