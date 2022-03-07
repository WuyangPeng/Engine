///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 10:23)

#include "Network/NetworkExport.h"

#include "MessageInterface.h"
#include "MessageInterfaceSharedPtrLess.h"

using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

bool Network::MessageInterfaceSharedPtrLess::operator()(const ConstMessageInterfaceSharedPtr& lhs, const ConstMessageInterfaceSharedPtr& rhs) const
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