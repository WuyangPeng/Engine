///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 16:18)

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
