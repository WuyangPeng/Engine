///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 19:02)

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistExport.h"

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssist.h"

#ifndef BUILDING_SHADOW_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_SHADOW_EDITOR_STATIC

namespace ShadowEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SHADOW_EDITOR_STATIC
