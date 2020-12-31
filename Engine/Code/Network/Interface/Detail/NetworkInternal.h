//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:05)

#ifndef NETWORK_NETWORK_INTERFACE_NETWORK_INTERNAL_H
#define NETWORK_NETWORK_INTERFACE_NETWORK_INTERNAL_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace Network
{
    [[nodiscard]] const System::String NETWORK_HIDDEN_DECLARE GetACELogName();
    [[nodiscard]] const System::String NETWORK_HIDDEN_DECLARE GetBoostLogName();
}

#endif  // NETWORK_NETWORK_INTERFACE_NETWORK_INTERNAL_H
