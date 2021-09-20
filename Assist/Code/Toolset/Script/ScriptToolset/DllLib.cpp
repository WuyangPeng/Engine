// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 11:57)

#include "Toolset/Script/ScriptToolset/ScriptToolsetExport.h"

#include "Toolset/Script/ScriptToolset/ScriptToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Script/ScriptLib.h"

#ifndef BUILDING_SCRIPT_STATIC

	#include "DllLib.h"

#else // BUILDING_SCRIPT_STATIC

	namespace ScriptToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCRIPT_STATIC
