// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.1 (2020/01/12 21:18)

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistExport.h"

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_TERRAIN_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_TERRAIN_EDITOR_STATIC

	namespace TerrainEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_TERRAIN_EDITOR_STATIC
