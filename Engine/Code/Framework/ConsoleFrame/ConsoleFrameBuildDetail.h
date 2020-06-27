// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_DETAIL_H

#include "ConsoleFrameBuild.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename ConsoleProcess>
Framework::ConsoleFrameBuild<ConsoleProcess>
	::ConsoleFrameBuild() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename ConsoleProcess>
Framework::ConsoleFrameBuild<ConsoleProcess>
	::~ConsoleFrameBuild()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ConsoleProcess>
bool Framework::ConsoleFrameBuild<ConsoleProcess>
	::IsValid() const noexcept
{
	  return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ConsoleProcess>
void Framework::ConsoleFrameBuild<ConsoleProcess>
	::EnterMessageLoop() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9; 
}
 
#endif // FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_DETAIL_H





