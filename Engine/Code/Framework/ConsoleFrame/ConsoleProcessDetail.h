// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_PROCESS_DETAIL_H
#define FRAMEWORK_CONSOLE_CONSOLE_PROCESS_DETAIL_H

#include "ConsoleProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

#ifdef OPEN_CLASS_INVARIANT
template <typename ConsoleCallBack>
bool Framework::ConsoleProcess<ConsoleCallBack>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT
 
#endif // FRAMEWORK_CONSOLE_CONSOLE_PROCESS_DETAIL_H
