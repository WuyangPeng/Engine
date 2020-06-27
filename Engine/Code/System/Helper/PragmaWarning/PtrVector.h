// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 19:31)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_PTR_VECTOR_H
#define SYSTEM_HELPER_PRAGMA_WARNING_PTR_VECTOR_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26433) 
	#include SYSTEM_WARNING_DISABLE(26440)   
	#include SYSTEM_WARNING_DISABLE(26455) 
	#include SYSTEM_WARNING_DISABLE(26481) 	

	#include <boost/ptr_container/ptr_vector.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_PTR_VECTOR_H
