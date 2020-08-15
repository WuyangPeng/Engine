// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:28)

#include "Network/NetworkExport.h"

#include "NetworkMessageEventLess.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

Network::NetworkMessageEventLess
	::NetworkMessageEventLess() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

bool Network::NetworkMessageEventLess
	::operator()(const NetworkMessageEventWeakPtr& lhs, const NetworkMessageEventWeakPtr& rhs) const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return lhs.lock() < rhs.lock();
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMessageEventLess);
