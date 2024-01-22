/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:16)

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
