// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 19:31)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_RECURSIVE_MUTEX_H
#define SYSTEM_HELPER_PRAGMA_WARNING_RECURSIVE_MUTEX_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(6388) 
	#include SYSTEM_WARNING_DISABLE(26451)  
	#include SYSTEM_WARNING_DISABLE(26498)  
	#include SYSTEM_WARNING_DISABLE(28251)  

	#include <boost/thread/recursive_mutex.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_RECURSIVE_MUTEX_H
