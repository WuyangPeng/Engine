// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_INIT_ONCE_FWD_H
#define SYSTEM_THREADING_INIT_ONCE_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/InitOnceUsing.h"

namespace System
{
	void SystemInitOnceInitialize(InitOncePtr initOnce) noexcept;
	bool SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowVoidPtr parameter, WindowVoidPtr* context) noexcept;
	bool SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowBoolPtr pending, WindowVoidPtr* context) noexcept;
	bool SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowVoidPtr context) noexcept;
}

#endif // SYSTEM_THREADING_INIT_ONCE_FWD_H