// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/21 21:00)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "Editor/Level/LevelEditorAssist/LevelEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_LEVEL_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_LEVEL_EDITOR_STATIC

	namespace LevelEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_LEVEL_EDITOR_STATIC
