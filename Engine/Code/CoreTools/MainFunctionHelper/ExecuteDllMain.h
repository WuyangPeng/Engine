// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:54)

#ifndef CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H
#define CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H

#include "CoreTools/CoreToolsDll.h"

#include "DllFunctionHelper.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/Using/WindowUsing.h"

namespace CoreTools
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
    inline void ExecuteDllMain([[maybe_unused]] System::WindowHInstance instance, System::WindowDWord reason, [[maybe_unused]] System::WindowVoidPtr reserved, CoreTools::DllMutex& mutex)
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
#include STSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_EXECUTE_DLL_MAIN_H