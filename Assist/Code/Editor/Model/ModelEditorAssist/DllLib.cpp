///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:58)

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
