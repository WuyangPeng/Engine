// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 15:53)

#ifndef SYSTEM_HELPER_XLCPP_H
#define SYSTEM_HELPER_XLCPP_H

#if defined(__ibmxl__)

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_XLCPP
		#define TCRE_USE_XLCPP 1
	#endif // TCRE_USE_XLCPP

	#ifndef TCRE_CLANG
		#define TCRE_CLANG 1
	#endif // TCRE_CLANG

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION __clang_version__
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "Clang ∞Ê±æ " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

	#if defined(__GNUC__) && (4 <= __GNUC__)
		#define SYSTEM_ATTRIBUTE_UNUSED __attribute__((unused))
	#endif // defined(__GNUC__) && (4 <= __GNUC__)

#endif // defined(__ibmxl__)

#endif // SYSTEM_HELPER_XLCPP_H
