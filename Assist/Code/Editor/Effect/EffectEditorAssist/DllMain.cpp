///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:49)

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistFwd.h"

#ifndef BUILDING_EFFECT_EDITOR_STATIC

DLL_MAIN_FUNCTION(EffectEditorAssist);

#else  // !BUILDING_EFFECT_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(EffectEditorAssist);

#endif  // BUILDING_EFFECT_EDITOR_STATIC
