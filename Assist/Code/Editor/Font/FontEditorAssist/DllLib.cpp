///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:46)

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
