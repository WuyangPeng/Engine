// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.2 (2020/01/24 19:30)

#include "Example/Script/ScriptExample/ScriptExampleExport.h"

#include "Example/Script/ScriptExample/ScriptExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_SCRIPT_EXAMPLE_STATIC

	namespace ScriptExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCRIPT_EXAMPLE_STATIC
