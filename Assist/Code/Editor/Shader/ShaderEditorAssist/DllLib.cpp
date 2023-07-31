///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:41)

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
