// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/14 23:33)

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistExport.h"

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SHADOW_EDITOR_STATIC

	DLL_MAIN_FUNCTION(ShadowEditorAssist);

#else // !BUILDING_SHADOW_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(ShadowEditorAssist);

#endif // BUILDING_SHADOW_EDITOR_STATIC
