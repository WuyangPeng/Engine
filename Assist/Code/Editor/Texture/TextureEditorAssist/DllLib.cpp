// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/18 23:43)

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssistExport.h"

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_TEXTURE_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_TEXTURE_EDITOR_STATIC

	namespace TextureEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_TEXTURE_EDITOR_STATIC
