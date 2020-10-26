//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 18:38)

#ifndef CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H
#define CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H

#include "CoreTools/CoreToolsDll.h"

#include "DllFunctionHelper.h"
#include "System/Window/Using/WindowUsing.h"

namespace CoreTools
{
    void CORE_TOOLS_DEFAULT_DECLARE ExecuteDllMain(System::WindowHInstance instance, System::WindowDWord reason, System::WindowVoidPtr reserved, CoreTools::DllMutex& mutex);
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H