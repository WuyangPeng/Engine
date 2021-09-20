// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.1 (2020/01/19 23:52)

#include "Editor/Font/FontEditorAssist/FontEditorAssistExport.h"

#include "Editor/Font/FontEditorAssist/FontEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FONT_EDITOR_STATIC

	DLL_MAIN_FUNCTION(FontEditorAssist);

#else // !BUILDING_FONT_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(FontEditorAssist);

#endif // BUILDING_FONT_EDITOR_STATIC
