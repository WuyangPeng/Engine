///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:39)

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
