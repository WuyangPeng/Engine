///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 17:20)

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistExport.h"

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssist.h"

#ifndef BUILDING_EFFECT_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_EFFECT_EDITOR_STATIC

namespace EffectEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EFFECT_EDITOR_STATIC
