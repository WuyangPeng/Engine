// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/19 22:19)

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistExport.h"

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_MATERIAL_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_MATERIAL_EDITOR_STATIC

	namespace MaterialEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_MATERIAL_EDITOR_STATIC
