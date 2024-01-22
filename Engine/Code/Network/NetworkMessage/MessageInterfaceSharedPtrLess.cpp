/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:23)

#include "Network/NetworkExport.h"

#include "MessageInterface.h"
#include "MessageInterfaceSharedPtrLess.h"
#include "System/Helper/Tools.h"

bool Network::MessageInterfaceSharedPtrLess::operator()(const ConstMessageInterfaceSharedPtr& lhs, const ConstMessageInterfaceSharedPtr& rhs) const
{
    System::UnusedFunction(lhs, rhs);

    if (lhs->GetMessageId() < rhs->GetMessageId())
        return true;
    else if (rhs->GetMessageId() < lhs->GetMessageId())
        return false;
    if (lhs->GetSubMessageId() < rhs->GetSubMessageId())
        return true;
    else if (rhs->GetSubMessageId() < lhs->GetSubMessageId())
        return false;
    else
        return std::string{ lhs->GetRttiType().GetName() } < std::string{ rhs->GetRttiType().GetName() };
}
