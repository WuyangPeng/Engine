///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 17:46)

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistExport.h"

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssist.h"

#ifndef BUILDING_SHADER_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_SHADER_EDITOR_STATIC

namespace ShaderEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SHADER_EDITOR_STATIC
