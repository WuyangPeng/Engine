// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 23:02)

#ifndef MAIL_LIB_H
#define MAIL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MAIL_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MailD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Mail.lib")
		#endif // _DEBUG

	#else // !BUILDING_MAIL_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MailStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MailStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MAIL_STATIC

#endif // TCRE_USE_MSVC 

#endif // MAIL_LIB_H
