// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_HANDLE_TOOLS_FWD_H
#define SYSTEM_THREADING_HANDLE_TOOLS_FWD_H 

#include "ThreadingFlagsFwd.h"

namespace System
{
	bool SetThreadHandleInformation(ThreadHandle object, HandleInformation mask, HandleInformation flags) noexcept;
	bool GetThreadHandleInformation(ThreadHandle object, HandleInformation* flags) noexcept;
	bool DuplicateThreadHandle(WindowHandle sourceProcessHandle, ThreadHandle sourceHandle, WindowHandle targetProcessHandle, ThreadHandlePtr targetHandle,
							   WindowDWord desiredAccess, bool inheritHandle, DuplicateOptions options) noexcept;
}

#endif // SYSTEM_THREADING_HANDLE_TOOLS_FWD_H