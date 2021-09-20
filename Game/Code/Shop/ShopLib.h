// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:00)

#ifndef SHOP_LIB_H
#define SHOP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SHOP_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ShopD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Shop.lib")
		#endif // _DEBUG

	#else // !BUILDING_SHOP_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ShopStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ShopStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SHOP_STATIC

#endif // TCRE_USE_MSVC 

#endif // SHOP_LIB_H
