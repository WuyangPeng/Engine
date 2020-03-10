// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.1.0 (2019/11/29 10:32)


#include "Network/NetworkExport.h" 

#include "SendSocket.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SendSocket
	::SendSocket()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SendSocket
	::~SendSocket()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocket)
