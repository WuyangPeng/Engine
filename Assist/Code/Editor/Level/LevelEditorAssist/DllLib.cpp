///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:07)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "Editor/Level/LevelEditorAssist/LevelEditorAssist.h"

#ifndef BUILDING_LEVEL_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_LEVEL_EDITOR_STATIC

namespace LevelEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_LEVEL_EDITOR_STATIC
