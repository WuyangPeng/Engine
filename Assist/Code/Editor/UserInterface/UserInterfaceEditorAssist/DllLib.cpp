// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 21:18)

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistExport.h"

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_USER_INTERFACE_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_USER_INTERFACE_EDITOR_STATIC

	namespace UserInterfaceEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_USER_INTERFACE_EDITOR_STATIC