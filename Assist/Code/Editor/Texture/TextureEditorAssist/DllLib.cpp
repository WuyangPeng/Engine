///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:20)

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
