// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 10:59)

#include "LibExample/Lua/LuaLibExample/LuaLibExampleExport.h"

#include "LibExample/Lua/LuaLibExample/LuaLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_LUA_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_LUA_LIB_EXAMPLE_STATIC

	namespace LuaLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_LUA_LIB_EXAMPLE_STATIC
