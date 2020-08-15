// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_WINDOWS_MUTEX_H
#define CORE_TOOLS_THREADING_WINDOWS_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Threading/Using/MutexUsing.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WindowsMutex : public MutexImpl
	{
	public:
		using ClassType = WindowsMutex;
		using ParentType = MutexImpl;
		using MutexHandle = System::WindowHandle;

	public:
		WindowsMutex() noexcept; 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void Initialize() override;
		void Delete() noexcept override;
		void Enter() override;
		bool TryEnter() noexcept override;
		void Leave()  noexcept override;

	private:
		MutexHandle m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_WINDOWS_MUTEX_H