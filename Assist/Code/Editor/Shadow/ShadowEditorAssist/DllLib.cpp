// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/13 23:43)

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistExport.h"

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_SHADOW_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_SHADOW_EDITOR_STATIC

	namespace ShadowEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SHADOW_EDITOR_STATIC
