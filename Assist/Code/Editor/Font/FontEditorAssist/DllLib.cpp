///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 11:16)

#include "Editor/Font/FontEditorAssist/FontEditorAssistExport.h"

#include "Editor/Font/FontEditorAssist/FontEditorAssist.h"

#ifndef BUILDING_FONT_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_FONT_EDITOR_STATIC

namespace FontEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_FONT_EDITOR_STATIC
