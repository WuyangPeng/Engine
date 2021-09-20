// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/17 0:04)

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistExport.h"

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_EDITOR_STATIC

	DLL_MAIN_FUNCTION(AnimationEditorAssist);

#else // !BUILDING_ANIMATION_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(AnimationEditorAssist);

#endif // BUILDING_ANIMATION_EDITOR_STATIC