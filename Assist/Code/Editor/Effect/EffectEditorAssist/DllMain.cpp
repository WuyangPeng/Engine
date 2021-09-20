// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/16 0:07)

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistExport.h"

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECT_EDITOR_STATIC

	DLL_MAIN_FUNCTION(EffectEditorAssist);

#else // !BUILDING_EFFECT_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(EffectEditorAssist);

#endif // BUILDING_EFFECT_EDITOR_STATIC
