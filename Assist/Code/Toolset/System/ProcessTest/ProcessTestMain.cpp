/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:44)

#include "System/Threading/Process.h"
#include "System/Threading/SyncTools.h"

int main() noexcept
{
    System::SystemSleep(100);

    System::ExitSystemProcess(0);
}