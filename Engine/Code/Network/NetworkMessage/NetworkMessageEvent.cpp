// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:37)

#include "Network/NetworkExport.h"

#include "NetworkMessageEvent.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

Network::NetworkMessageEvent ::NetworkMessageEvent() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkMessageEvent
	::~NetworkMessageEvent()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMessageEvent);
