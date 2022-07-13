///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 19:02)

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistFwd.h"

#ifndef BUILDING_SHADOW_EDITOR_STATIC

DLL_MAIN_FUNCTION(ShadowEditorAssist);

#else  // !BUILDING_SHADOW_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ShadowEditorAssist);

#endif  // BUILDING_SHADOW_EDITOR_STATIC
