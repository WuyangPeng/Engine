///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:49)

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
