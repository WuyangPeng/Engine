// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/02/28 02:08)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ENGINE_DISABLE_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ENGINE_DISABLE_H 

// 警告：函数<func>中缺少注释<annotation>。
#if defined(TCRE_USE_MSVC)
	#pragma warning(disable : 26135) 
#endif // TCRE_USE_MSVC  

// 警告：优先使用gsl::at()而非未选中的下标运算符。
#if defined(TCRE_USE_MSVC)
	#pragma warning(disable : 26446) 
#endif // TCRE_USE_MSVC  

#endif // SYSTEM_HELPER_PRAGMA_WARNING_ENGINE_DISABLE_H
