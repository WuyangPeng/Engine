///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/29 22:14)

#ifndef CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H
#define CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H

#include "CoreTools/CoreToolsDll.h"

#include "DllFunctionHelper.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace CoreTools
{
    void CORE_TOOLS_DEFAULT_DECLARE ExecuteDllMain(MAYBE_UNUSED System::WindowsHInstance instance,
                                                   System::WindowsDWord reason,
                                                   MAYBE_UNUSED System::WindowsVoidPtr reserved,
                                                   CoreTools::DllMutex& mutex);
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H