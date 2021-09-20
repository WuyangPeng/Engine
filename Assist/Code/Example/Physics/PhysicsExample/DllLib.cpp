// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.2 (2020/01/26 16:00)

#include "Example/Physics/PhysicsExample/PhysicsExampleExport.h"

#include "Example/Physics/PhysicsExample/PhysicsExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_PHYSICS_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_PHYSICS_EXAMPLE_STATIC

	namespace PhysicsExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_PHYSICS_EXAMPLE_STATIC
