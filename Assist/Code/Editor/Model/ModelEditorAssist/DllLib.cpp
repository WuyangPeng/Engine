// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/18 20:50)

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistExport.h"

#include "Editor/Model/ModelEditorAssist/ModelEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_MODEL_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_MODEL_EDITOR_STATIC

	namespace ModelEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_MODEL_EDITOR_STATIC
