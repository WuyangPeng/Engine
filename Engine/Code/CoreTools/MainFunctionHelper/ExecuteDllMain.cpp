///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/29 22:31)

#include "CoreTools/CoreToolsExport.h"

#include "ExecuteDllMain.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/Helper/EnumCast.h"

void CoreTools::ExecuteDllMain(MAYBE_UNUSED System::WindowsHInstance instance, System::WindowsDWord reason, MAYBE_UNUSED System::WindowsVoidPtr reserved, DllMutex& mutex)
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
