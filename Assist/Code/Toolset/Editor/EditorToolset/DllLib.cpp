// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/12 1:24)

#include "Toolset/Editor/EditorToolset/EditorToolsetExport.h"

#include "Toolset/Editor/EditorToolset/EditorToolset.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_EDITOR_STATIC

	namespace EditorToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_EDITOR_STATIC
