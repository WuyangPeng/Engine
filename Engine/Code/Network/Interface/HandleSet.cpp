// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/29 10:31)


#include "Network/NetworkExport.h" 

#include "HandleSet.h"
#include "Detail/HandleSetImpl.h"
#include "Detail/HandleSetFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::HandleSet
	::HandleSet(const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ HandleSetFactory::Create(configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, HandleSet)

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Network, HandleSet)
DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(Network, HandleSet)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, SetBit, ACEHandle, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetMaxSet, int64_t)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetFdSet, Network::SockFdSet*)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, Sync, ACEHandle, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, isSet, ACEHandle, bool)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, ClearBit, ACEHandle, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetACEHandleSet, const Network::ACEHandleSet&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetFull, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetCount, int)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, Select, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetCountIsOne, bool) 

