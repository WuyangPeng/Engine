// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 23:13)

#ifndef GUILD_LIB_H
#define GUILD_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GUILD_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GuildD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Guild.lib")
		#endif // _DEBUG

	#else // !BUILDING_GUILD_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GuildStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GuildStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_GUILD_STATIC

#endif // TCRE_USE_MSVC 

#endif // GUILD_LIB_H
