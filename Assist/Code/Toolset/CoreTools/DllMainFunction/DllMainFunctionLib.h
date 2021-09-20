///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/15 11:39)

#ifndef DLL_MAIN_FUNCTION_LIB_H
#define DLL_MAIN_FUNCTION_LIB_H

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DllMainFunctionD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DllMainFunction.lib")
		#endif // _DEBUG

	#else // !BUILDING_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DllMainFunctionStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DllMainFunctionStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_STATIC

#endif // TCRE_USE_MSVC 

#endif // DLL_MAIN_FUNCTION_LIB_H