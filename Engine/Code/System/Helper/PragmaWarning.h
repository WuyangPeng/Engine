// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.3 (2020/03/02 10:18)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_PRAGMA_WARNING_H
#define SYSTEM_HELPER_PRAGMA_WARNING_PRAGMA_WARNING_H 

#include "System/Helper/ConfigMacro.h"

#define STSTEM_WARNING_PUSH "System/Helper/PragmaWarning/Push.h" 
#define SYSTEM_WARNING_DISABLE(index) SYSTEM_STRINGIZE(SYSTEM_MULTIPLE_CONCATENATOR(System/Helper/PragmaWarning/Disable,index,.h))
#define STSTEM_WARNING_POP "System/Helper/PragmaWarning/Pop.h" 
	  
#endif // SYSTEM_HELPER_PRAGMA_WARNING_PRAGMA_WARNING_H
