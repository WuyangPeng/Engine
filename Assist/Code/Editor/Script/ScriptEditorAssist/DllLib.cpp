///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 16:44)

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
