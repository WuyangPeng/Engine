/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:16)

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
