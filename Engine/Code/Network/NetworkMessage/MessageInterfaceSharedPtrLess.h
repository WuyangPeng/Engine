///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:28)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_SHARED_PTR_LESS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_SHARED_PTR_LESS_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageInterfaceSharedPtrLess final
    {
    public:
        using ClassType = MessageInterfaceSharedPtrLess;

    public:
        NODISCARD bool operator()(const ConstMessageInterfaceSharedPtr& lhs, const ConstMessageInterfaceSharedPtr& rhs) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_SHARED_PTR_LESS_H
