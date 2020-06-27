// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:27)

#ifndef SYSTEM_THREADING_INIT_ONCE_H
#define SYSTEM_THREADING_INIT_ONCE_H

#include "System/SystemDll.h"

#include "Using/InitOnceUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	void SYSTEM_DEFAULT_DECLARE SystemInitOnceInitialize(InitOncePtr initOnce) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowVoidPtr parameter, WindowVoidPtr* context) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowBoolPtr pending, WindowVoidPtr* context) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowVoidPtr context) noexcept;
}

#endif // SYSTEM_THREADING_INIT_ONCE_H