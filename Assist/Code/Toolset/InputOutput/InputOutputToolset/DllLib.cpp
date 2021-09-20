// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 19:05)

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetExport.h"

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "InputOutput/InputOutputLib.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

	#include "DllLib.h"

#else // BUILDING_INPUT_OUTPUT_STATIC

	namespace InputOutputToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_INPUT_OUTPUT_STATIC
