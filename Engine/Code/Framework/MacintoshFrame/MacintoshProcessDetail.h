// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_DETAIL_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_DETAIL_H

#include "MacintoshProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

#ifdef OPEN_CLASS_INVARIANT
template <typename MacintoshCallBack>
bool Framework::MacintoshProcess<MacintoshCallBack>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT
 
#endif // FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_DETAIL_H
