///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/15 16:18)

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistExport.h"

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssist.h"

#ifndef BUILDING_ANIMATION_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_ANIMATION_EDITOR_STATIC

namespace AnimationEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ANIMATION_EDITOR_STATIC
