// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/29 10:31)


#include "Network/NetworkExport.h" 

#include "HandleSetIterator.h"
#include "Detail/HandleSetIteratorFactory.h"
#include "Detail/HandleSetIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::HandleSetIterator
	::HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
	:m_Impl{ HandleSetIteratorFactory::Create(configurationStrategy, handleSet) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, HandleSetIterator)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSetIterator, operator(), Network::ACEHandle)