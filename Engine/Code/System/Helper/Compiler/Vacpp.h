// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:02)

#ifndef SYSTEM_HELPER_VACPP_H
#define SYSTEM_HELPER_VACPP_H

#if defined(__IBMCPP__)

	// Visual Age (IBM) C++ ±‡“Î∆˜…Ë÷√£∫
 
	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_VACPP
		#define TCRE_USE_VACPP 1
	#endif // TCRE_USE_VACPP

	#ifndef COMPILER_VERSION
		#define COMPILER_VERSION __IBMCPP__
	#endif // COMPILER_VERSION

	#ifndef SYSTEM_COMPILER
		#define SYSTEM_COMPILER "IBM Visual Age ∞Ê±æ " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // SYSTEM_COMPILER

	#if __IBMCPP__ < 500
		#error "±‡“Î∆˜Œ¥≈‰÷√"
	#endif // __IBMCPP__ < 500

	#if (1210 < __IBMCPP__)
		#error "Œ¥÷™±‡“Î∆˜"
	#endif // (1210 < __IBMCPP__) 

#endif // defined(__IBMCPP__)

#endif // SYSTEM_HELPER_VACPP_H
