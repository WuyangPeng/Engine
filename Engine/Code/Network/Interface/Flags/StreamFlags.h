//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 15:30)

#ifndef NETWORK_BOOST_WRAPPERS_STREAM_FLAGS_H
#define NETWORK_BOOST_WRAPPERS_STREAM_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
    enum class StreamReceive
    {
        Head = 0,
        Content = 1
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_STREAM_FLAGS_H
