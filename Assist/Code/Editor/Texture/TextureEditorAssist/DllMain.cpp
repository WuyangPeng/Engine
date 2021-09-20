// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/18 23:44)

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssistExport.h"

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TEXTURE_EDITOR_STATIC

	DLL_MAIN_FUNCTION(TextureEditorAssist);

#else // !BUILDING_TEXTURE_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(TextureEditorAssist);

#endif // BUILDING_TEXTURE_EDITOR_STATIC
