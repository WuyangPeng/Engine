//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 9:52)

#include "CoreTools/CoreToolsExport.h"

#include "ExecuteDllMain.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/Helper/EnumCast.h"

void CoreTools::ExecuteDllMain([[maybe_unused]] System::WindowHInstance instance, System::WindowDWord reason, [[maybe_unused]] System::WindowVoidPtr reserved, DllMutex& mutex)
{
    switch (System::UnderlyingCastEnum<System::DllMain>(reason))
    {
        case System::DllMain::ProcessAttach:
            CoreTools::DllFunctionHelper::InitializeMutex(&mutex);
            break;
        case System::DllMain::ProcessDetach:
            CoreTools::DllFunctionHelper::DeleteMutex(&mutex);
            break;
        default:
            break;
    }
}