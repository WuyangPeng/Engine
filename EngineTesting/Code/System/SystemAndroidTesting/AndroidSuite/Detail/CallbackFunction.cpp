///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 22:50)

#include "CallbackFunction.h"
#include "System/Helper/Tools.h"

int System::Android::Looper::CallbackFunction(int fd, int events, void* data) noexcept
{
    UnusedFunction(fd, events, data);

    return 0;
}
