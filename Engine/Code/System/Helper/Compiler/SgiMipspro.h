// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:02)

#ifndef SYSTEM_HELPER_SGI_MIPSPRO_H
#define SYSTEM_HELPER_SGI_MIPSPRO_H

#if defined(__sgi)

	// SGI C++ ±‡“Î∆˜…Ë÷√£∫

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_SGI_MIPSPRO
		#define TCRE_USE_SGI_MIPSPRO 1
	#endif // TCRE_USE_SGI_MIPSPRO

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION _COMPILER_VERSION
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "SGI Irix ±‡“Î∆˜∞Ê±æ " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER 

#endif // defined(__sgi)

#endif // SYSTEM_HELPER_SGI_MIPSPRO_H
