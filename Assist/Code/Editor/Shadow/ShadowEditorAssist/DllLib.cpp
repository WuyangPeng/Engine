///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:34)

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
