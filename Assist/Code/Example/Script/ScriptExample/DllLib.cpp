///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 11:05)

#include "Example/Script/ScriptExample/ScriptExampleExport.h"

#include "Example/Script/ScriptExample/ScriptExample.h"

#ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_SCRIPT_EXAMPLE_STATIC

namespace ScriptExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCRIPT_EXAMPLE_STATIC
