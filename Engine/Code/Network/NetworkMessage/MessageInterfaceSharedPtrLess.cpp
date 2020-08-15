// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:35)

#include "Network/NetworkExport.h"

#include "MessageInterfaceSharedPtrLess.h"
#include "MessageInterface.h"

using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

bool Network::MessageInterfaceSharedPtrLess
	::operator()(const ConstMessageInterfaceSharedPtr& lhs, const ConstMessageInterfaceSharedPtr& rhs)
{
	if (lhs->GetMessageID() < rhs->GetMessageID())
		return true;
	else if (rhs->GetMessageID() < lhs->GetMessageID())
		return false;
	if (lhs->GetSubMessageID() < rhs->GetSubMessageID())
		return true;
	else if (rhs->GetSubMessageID() < lhs->GetSubMessageID())
		return false;
	else
		return string{ lhs->GetRttiType().GetName() } < string{ rhs->GetRttiType().GetName() };
}
#include STSTEM_WARNING_POP