///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:52)

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
