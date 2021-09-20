// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/17 0:04)

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssistExport.h"

#include "Editor/Animation/AnimationEditorAssist/AnimationEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_ANIMATION_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_ANIMATION_EDITOR_STATIC

	namespace AnimationEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ANIMATION_EDITOR_STATIC
