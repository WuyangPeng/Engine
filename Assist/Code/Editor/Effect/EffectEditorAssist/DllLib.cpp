// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/16 0:07)

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistExport.h"

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_EFFECT_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_EFFECT_EDITOR_STATIC

	namespace EffectEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_EFFECT_EDITOR_STATIC
