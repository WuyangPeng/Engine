//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 13:11)

#include "Network/NetworkExport.h"

#include "HandleSet.h"
#include "Detail/HandleSetFactory.h"
#include "Detail/HandleSetImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::HandleSet::HandleSet(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ HandleSetFactory::Create(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, HandleSet)

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Network, HandleSet)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, SetBit, ACEHandle, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetMaxSet, int64_t)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetFdSet, Network::SockFdSet*)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, Sync, ACEHandle, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, IsSet, ACEHandle, bool)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, ClearBit, ACEHandle, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, GetACEHandleSet, const Network::ACEHandleSet&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetFull, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetCount, int)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Network, HandleSet, Select, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSet, IsFdSetCountIsOne, bool)
