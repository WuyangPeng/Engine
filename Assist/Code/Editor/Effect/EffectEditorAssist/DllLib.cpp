///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:21)

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
