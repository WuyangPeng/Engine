///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:01)

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistExport.h"

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssist.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_MATERIAL_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_MATERIAL_EDITOR_STATIC

namespace MaterialEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MATERIAL_EDITOR_STATIC
