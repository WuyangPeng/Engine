// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/15 21:43)

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistExport.h"

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_SCENE_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_SCENE_EDITOR_STATIC

	namespace SceneEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCENE_EDITOR_STATIC
