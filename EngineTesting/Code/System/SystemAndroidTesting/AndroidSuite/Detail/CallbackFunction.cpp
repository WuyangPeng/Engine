///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 22:50)

#include "CallbackFunction.h"
#include "System/Helper/Tools.h"

int System::Android::Looper::CallbackFunction(int fd, int events, void* data) noexcept
{
    UnusedFunction(fd, events, data);

    return 0;
}
