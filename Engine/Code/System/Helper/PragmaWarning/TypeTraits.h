// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 19:31)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
#define SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
	
	#include SYSTEM_WARNING_DISABLE(26440) 
	#include SYSTEM_WARNING_DISABLE(26471) 
	#include SYSTEM_WARNING_DISABLE(26485)	

	#include <boost/type_traits/has_less.hpp>
	#include <boost/type_traits/has_minus.hpp> 
	#include <boost/type_traits/has_greater.hpp>
	#include <boost/type_traits/has_equal_to.hpp>
	#include <boost/type_traits/has_less_equal.hpp>
	#include <boost/type_traits/has_not_equal_to.hpp>
	#include <boost/type_traits/has_greater_equal.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
