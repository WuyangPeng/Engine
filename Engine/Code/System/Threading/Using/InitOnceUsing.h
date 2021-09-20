///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/04/25 13:56)

#ifndef SYSTEM_THREADING_INIT_ONCE_USING_H
#define SYSTEM_THREADING_INIT_ONCE_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using InitOnce = INIT_ONCE;
    using InitOncePtr = PINIT_ONCE;
    using InitOnceFunction = PINIT_ONCE_FN;

#else  // !SYSTEM_PLATFORM_WIN32

    struct InitOnce
    {
        void* Ptr;
    };
    using InitOncePtr = InitOnce*;
    using InitOnceFunction = int (*)(InitOncePtr initOnce, void* parameter, void** context);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_INIT_ONCE_USING_H