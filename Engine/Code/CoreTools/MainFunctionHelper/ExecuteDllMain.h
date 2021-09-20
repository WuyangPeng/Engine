//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 18:38)

#ifndef CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H
#define CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H

#include "CoreTools/CoreToolsDll.h"

#include "DllFunctionHelper.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace CoreTools
{
    void CORE_TOOLS_DEFAULT_DECLARE ExecuteDllMain(System::WindowsHInstance instance, System::WindowsDWord reason, System::WindowsVoidPtr reserved, CoreTools::DllMutex& mutex);
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H