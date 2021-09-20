// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.2 (2020/01/24 0:15)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "Example/Database/DatabaseExample/DatabaseExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_DATABASE_EXAMPLE_STATIC

	namespace DatabaseExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_DATABASE_EXAMPLE_STATIC
