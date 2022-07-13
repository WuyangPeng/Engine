///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/08 16:57)

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistExport.h"

#include "CoreTools/CoreToolsLib.h"
#include "Editor/Model/ModelEditorAssist/ModelEditorAssist.h"

#ifndef BUILDING_MODEL_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_MODEL_EDITOR_STATIC

namespace ModelEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MODEL_EDITOR_STATIC
