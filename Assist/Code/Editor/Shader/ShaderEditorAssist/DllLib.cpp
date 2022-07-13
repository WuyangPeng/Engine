///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 17:46)

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
