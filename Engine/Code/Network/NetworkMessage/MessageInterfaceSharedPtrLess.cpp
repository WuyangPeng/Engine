///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/08 09:58)

#include "Network/NetworkExport.h"

#include "MessageInterface.h"
#include "MessageInterfaceSharedPtrLess.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

bool Network::MessageInterfaceSharedPtrLess::operator()(const ConstMessageInterfaceSharedPtr& lhs, const ConstMessageInterfaceSharedPtr& rhs) const
{
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

#include STSTEM_WARNING_POP