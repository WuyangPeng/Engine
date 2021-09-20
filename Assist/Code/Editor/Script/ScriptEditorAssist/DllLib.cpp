// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/21 21:31)

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistExport.h"

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_SCRIPT_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_SCRIPT_EDITOR_STATIC

	namespace ScriptEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCRIPT_EDITOR_STATIC
