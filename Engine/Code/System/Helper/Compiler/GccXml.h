// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:01)

#ifndef SYSTEM_HELPER_GCC_XML_H
#define SYSTEM_HELPER_GCC_XML_H

#ifdef __GCCXML__

	// GCC-XML C++ ±‡“Î∆˜…Ë÷√£∫

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_GCC_XML
		#define TCRE_USE_GCC_XML 1
	#endif // TCRE_USE_GCC_XML

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION __GCCXML__
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "GCC-XML C++ ∞Ê±æ " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

#endif // __GCCXML__ 

#endif // SYSTEM_HELPER_GCC_XML_H


 

