///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/15 15:08)

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistExport.h"

#include "CoreTools/CoreToolsLib.h"
#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssist.h"

#ifndef BUILDING_SCRIPT_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_SCRIPT_EDITOR_STATIC

namespace ScriptEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCRIPT_EDITOR_STATIC
