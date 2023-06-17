///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2022/07/06 15:24)

#include "Editor/Data/DataEditorAssist/DataEditorAssistExport.h"

#include "Editor/Data/DataEditorAssist/DataEditorAssist.h"

#ifndef BUILDING_DATA_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATA_EDITOR_STATIC

namespace DataEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATA_EDITOR_STATIC
