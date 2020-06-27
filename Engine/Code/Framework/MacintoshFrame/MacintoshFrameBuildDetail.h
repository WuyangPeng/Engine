// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H

#include "MacintoshFrameBuild.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename MacintoshProcess>
Framework::MacintoshFrameBuild<MacintoshProcess>
	::MacintoshFrameBuild() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename MacintoshProcess>
Framework::MacintoshFrameBuild<MacintoshProcess>
	::~MacintoshFrameBuild()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename MacintoshProcess>
bool Framework::MacintoshFrameBuild<MacintoshProcess>
	::IsValid() const noexcept
{
	  return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MacintoshProcess>
void Framework::MacintoshFrameBuild<MacintoshProcess>
	::EnterMessageLoop() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9; 
}
 
#endif // FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H





