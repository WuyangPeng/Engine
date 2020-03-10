// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_WINDOW_NAMED_PIPE_FWD_H 
#define SYSTEM_WINDOW_WINDOW_NAMED_PIPE_FWD_H  

#include "System/Security/Using/SecurityBaseUsing.h" 

namespace System
{
	bool CreateSystemPipe(WindowHandlePtr readPipe, WindowHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowDWord size) noexcept;
	bool CloseSystemPipe(WindowHandle pipeHandle) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_NAMED_PIPE_FWD_H