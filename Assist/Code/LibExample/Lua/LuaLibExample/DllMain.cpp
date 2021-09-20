// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 10:59)

#include "LibExample/Lua/LuaLibExample/LuaLibExampleExport.h"

#include "LibExample/Lua/LuaLibExample/LuaLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LUA_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(LuaLibExample);

#else // !BUILDING_LUA_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(LuaLibExample);

#endif // !BUILDING_LUA_LIB_EXAMPLE_STATIC
