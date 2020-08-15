// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:12)

#include "Network/NetworkExport.h"

#include "NullMainManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::NullMainManager
	::NullMainManager() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMainManager)

void Network::NullMainManager ::Run() noexcept
{
	NETWORK_CLASS_IS_VALID_9;
}

void Network::NullMainManager ::StopContext() noexcept
{
	NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullMainManager ::IsContextStop() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return false;
}

void Network::NullMainManager ::RestartContext() noexcept
{
	NETWORK_CLASS_IS_VALID_9;
}

