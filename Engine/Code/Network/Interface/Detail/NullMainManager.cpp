// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 17:22)

#include "Network/NetworkExport.h"

#include "NullMainManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::NullMainManager
	::NullMainManager()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullMainManager
	::~NullMainManager()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMainManager) 

void Network::NullMainManager
	::Run()
{
	NETWORK_CLASS_IS_VALID_9;
}

void Network::NullMainManager
	::StopContext()
{
	NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullMainManager
	::IsContextStop() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return false;
}

void Network::NullMainManager
	::RestartContext()
{
	NETWORK_CLASS_IS_VALID_9;
}

