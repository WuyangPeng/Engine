/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:08)

#include "CallbackFunction.h"
#include "System/Helper/Tools.h"

int System::Android::Looper::CallbackFunction(int fileDescriptor, int events, void* data) noexcept
{
    UnusedFunction(fileDescriptor, events, data);

    return 0;
}
