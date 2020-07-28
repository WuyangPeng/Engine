// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 19:31)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_TIMER_H
#define SYSTEM_HELPER_PRAGMA_WARNING_TIMER_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
	
	#include SYSTEM_WARNING_DISABLE(26409) 
	#include SYSTEM_WARNING_DISABLE(26440) 	
	#include SYSTEM_WARNING_DISABLE(26495) 
	#include SYSTEM_WARNING_DISABLE(26814) 

	#include <boost/timer/timer.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_TIMER_H
