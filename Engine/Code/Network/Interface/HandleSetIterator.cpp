// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:55)

#include "Network/NetworkExport.h" 

#include "HandleSetIterator.h"
#include "Detail/HandleSetIteratorFactory.h"
#include "Detail/HandleSetIteratorImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::HandleSetIterator
	::HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
	:m_Impl{ HandleSetIteratorFactory::Create(configurationStrategy, handleSet) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, HandleSetIterator)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSetIterator, operator(), Network::ACEHandle)