/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:15)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_LENGTH_FLAGS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_LENGTH_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
    enum class BuffBlockSize
    {
        Size256 = 256,
        Size512 = Size256 << 1,
        Size1024 = Size512 << 1,
        Size2048 = Size512 << 2,
        Size4096 = Size512 << 3,
        Size8K = Size512 << 4,
        Size16K = Size512 << 5,
        Size32K = Size512 << 6,
        Size64K = Size512 << 7,
        Size128K = Size512 << 8,
        Size256K = Size512 << 9,
        Size512K = Size512 << 10,
        Automatic,
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_LENGTH_FLAGS_H
