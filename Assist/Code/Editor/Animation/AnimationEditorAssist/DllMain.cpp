///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 14:21)

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistFwd.h"

#ifndef BUILDING_ANIMATION_EDITOR_STATIC

DLL_MAIN_FUNCTION(AnimationEditorAssist);

#else  // !BUILDING_ANIMATION_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(AnimationEditorAssist);

#endif  // BUILDING_ANIMATION_EDITOR_STATIC
