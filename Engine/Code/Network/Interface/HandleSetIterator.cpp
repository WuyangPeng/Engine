//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:11)

#include "Network/NetworkExport.h"

#include "HandleSetIterator.h"
#include "Detail/HandleSetIteratorFactory.h"
#include "Detail/HandleSetIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::HandleSetIterator::HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
    : m_Impl{ HandleSetIteratorFactory::Create(configurationStrategy, handleSet) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, HandleSetIterator)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSetIterator, operator(), Network::ACEHandle)