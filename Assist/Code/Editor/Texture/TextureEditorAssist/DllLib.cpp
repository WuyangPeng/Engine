///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 13:46)

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssistExport.h"

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssist.h"

#ifndef BUILDING_TEXTURE_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_TEXTURE_EDITOR_STATIC

namespace TextureEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_TEXTURE_EDITOR_STATIC
