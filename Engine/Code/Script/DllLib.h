// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 13:26)

#ifndef SCRIPT_DLL_LIB_H
#define SCRIPT_DLL_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifdef SCRIPT_USE_LUA 
		#pragma comment(lib,"lua.lib") 
	#endif // SCRIPT_USE_LUA
	
#endif // TCRE_USE_MSVC

#endif // SCRIPT_DLL_LIB_H