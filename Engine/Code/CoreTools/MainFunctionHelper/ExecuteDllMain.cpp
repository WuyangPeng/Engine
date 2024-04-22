/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:49)

#include "CoreTools/CoreToolsExport.h"

#include "ExecuteDllMain.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"

void CoreTools::ExecuteDllMain(System::WindowsHInstance instance, System::WindowsDWord reason, System::WindowsVoidPtr reserved, DllMutex& mutex)
{
    System::UnusedFunction(instance, reserved);

    switch (System::UnderlyingCastEnum<System::DllMain>(reason))
    {
        case System::DllMain::ProcessAttach:
            DllFunctionHelper::InitializeMutex(&mutex);
            break;
        case System::DllMain::ProcessDetach:
            DllFunctionHelper::DeleteMutex(&mutex);
            break;
        default:
            break;
    }
}
