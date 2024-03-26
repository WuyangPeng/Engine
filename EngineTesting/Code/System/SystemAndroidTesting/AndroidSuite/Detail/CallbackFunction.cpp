/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:08)

#include "CallbackFunction.h"
#include "System/Helper/Tools.h"

int System::Android::Looper::CallbackFunction(int fileDescriptor, int events, void* data) noexcept
{
    UnusedFunction(fileDescriptor, events, data);

    return 0;
}
