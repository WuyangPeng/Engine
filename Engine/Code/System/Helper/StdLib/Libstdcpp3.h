// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 17:57)

#ifndef SYSTEM_HELPER_LIBSTDCPP3_H
#define SYSTEM_HELPER_LIBSTDCPP3_H 

#if defined(__GLIBCPP__) || defined(__GLIBCXX__)

	#ifndef TCRE_CPPLIB_VERSION
		#ifdef __GLIBCXX__
			#define TCRE_CPPLIB_VERSION __GLIBCXX__
		#else // !__GLIBCXX__
			#define TCRE_CPPLIB_VERSION __GLIBCPP__
		#endif // __GLIBCXX__
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "GNU libstdc++ ∞Ê±æ " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
	#endif // !TCRE_STDLIB 

	#define TCRE_USE_LIBSTDCPP3

#endif // defined(__GLIBCPP__) || defined(__GLIBCXX__)

#endif // SYSTEM_HELPER_LIBSTDCPP3_H
