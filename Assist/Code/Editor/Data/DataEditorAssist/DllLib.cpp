// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/16 21:10)

#include "Editor/Data/DataEditorAssist/DataEditorAssistExport.h"

#include "Editor/Data/DataEditorAssist/DataEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_DATA_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_DATA_EDITOR_STATIC

	namespace DataEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_DATA_EDITOR_STATIC
