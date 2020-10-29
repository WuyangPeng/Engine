//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 14:05)

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