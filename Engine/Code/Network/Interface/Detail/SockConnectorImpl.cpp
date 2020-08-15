// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:28)

#include "Network/NetworkExport.h" 

#include "SockConnectorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::SockConnectorImpl
	::SockConnectorImpl() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockConnectorImpl
	::~SockConnectorImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockConnectorImpl)
