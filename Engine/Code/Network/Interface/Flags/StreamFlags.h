/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:44)

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
