// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:43)

#ifndef FRAMEWORK_LINUX_LINUX_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_LINUX_LINUX_FRAME_BUILD_DETAIL_H

#include "LinuxFrameBuild.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename LinuxProcess>
Framework::LinuxFrameBuild<LinuxProcess>
	::LinuxFrameBuild() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename LinuxProcess>
Framework::LinuxFrameBuild<LinuxProcess>
	::~LinuxFrameBuild()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename LinuxProcess>
bool Framework::LinuxFrameBuild<LinuxProcess>
	::IsValid() const noexcept
{
	  return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename LinuxProcess>
void Framework::LinuxFrameBuild<LinuxProcess>
	::EnterMessageLoop() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9; 
}
 
#endif // FRAMEWORK_LINUX_LINUX_FRAME_BUILD_DETAIL_H





