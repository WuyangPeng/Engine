// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/19 23:52)

#include "Editor/Font/FontEditorAssist/FontEditorAssistExport.h"

#include "Editor/Font/FontEditorAssist/FontEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_FONT_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_FONT_EDITOR_STATIC

	namespace FontEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FONT_EDITOR_STATIC
