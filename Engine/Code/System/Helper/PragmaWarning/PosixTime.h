// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/15 17:33)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_POSIX_TIME_H
#define SYSTEM_HELPER_PRAGMA_WARNING_POSIX_TIME_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26444) 
#include SYSTEM_WARNING_DISABLE(26451)  
#include SYSTEM_WARNING_DISABLE(26495)  
#include SYSTEM_WARNING_DISABLE(28251) 

	#include <boost/date_time/posix_time/posix_time.hpp>

#include STSTEM_WARNING_POP
	  
#endif // SYSTEM_HELPER_PRAGMA_WARNING_POSIX_TIME_H
