///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/01/30 13:01)

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