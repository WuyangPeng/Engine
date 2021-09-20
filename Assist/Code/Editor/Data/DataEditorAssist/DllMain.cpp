// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.1 (2020/01/16 21:10)

#include "Editor/Data/DataEditorAssist/DataEditorAssistExport.h"

#include "Editor/Data/DataEditorAssist/DataEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATA_EDITOR_STATIC

	DLL_MAIN_FUNCTION(DataEditorAssist);

#else // !BUILDING_DATA_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(DataEditorAssist);

#endif // BUILDING_DATA_EDITOR_STATIC
