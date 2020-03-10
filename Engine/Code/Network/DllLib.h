// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/09 19:16)

#ifndef NETWORK_DLL_LIB_H
#define NETWORK_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifdef NETWORK_USE_ACE
		#ifdef _DEBUG
			#pragma comment(lib,"ACEd.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ACE.lib")
		#endif // _DEBUG
	#endif // NETWORK_USE_ACE

	#ifdef NETWORK_USE_OPENSSL
		#pragma comment(lib,"libssl.lib")
		#pragma comment(lib,"libcrypto.lib")
	#endif // NETWORK_USE_OPENSSL

#endif // TCRE_USE_MSVC

#endif // NETWORK_DLL_LIB_H