///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/04 13:41)

#ifndef NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_INTERNAL_FWD_H
#define NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_INTERNAL_FWD_H

#include "Network/NetworkDll.h"

#include "NetworkMessageFwd.h"
#include "Network/Configuration/ConfigurationFwd.h"

#include <memory>

namespace Network
{
    class MessageBufferImpl;
    class MessageEventContainerImpl;
    class MultiMessageEventContainerImpl;

    class MessageBufferFactory;
}

#endif  // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_INTERNAL_FWD_H
