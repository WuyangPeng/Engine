///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/06 14:21)

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistFwd.h"

#ifndef BUILDING_ANIMATION_EDITOR_STATIC

DLL_MAIN_FUNCTION(AnimationEditorAssist);

#else  // !BUILDING_ANIMATION_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(AnimationEditorAssist);

#endif  // BUILDING_ANIMATION_EDITOR_STATIC
