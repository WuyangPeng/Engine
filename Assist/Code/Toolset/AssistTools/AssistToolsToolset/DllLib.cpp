// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/10 23:28)

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetExport.h"

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "AssistTools/AssistToolsLib.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

	#include "DllLib.h"

#else // BUILDING_ASSIST_TOOLS_STATIC

	namespace AssistToolsToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ASSIST_TOOLS_STATIC