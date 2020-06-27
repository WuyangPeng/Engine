// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/17 10:56)

#ifndef SCRIPT_DLL_LIB_H
#define SCRIPT_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifdef SCRIPT_USE_LUA 
		#pragma comment(lib,"lua.lib") 
	#endif // SCRIPT_USE_LUA
	
#endif // TCRE_USE_MSVC

#endif // SCRIPT_DLL_LIB_H