// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:07)

#ifndef CORE_TOOLS_THREADING_EVENT_IMPL_H
#define CORE_TOOLS_THREADING_EVENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Using/WindowUsing.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE EventImpl
	{
	public:
		using ClassType = EventImpl;
		using EventHandle = System::WindowHandle;

	public:
		EventImpl(bool manualReset, bool initialState);
		~EventImpl();
		EventImpl(const EventImpl&) = delete;
		EventImpl& operator=(const EventImpl&) = delete;
		EventImpl(EventImpl&&) noexcept = delete;
		EventImpl& operator=(EventImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		void SetEvent();
		void ResetEvent();
		void Wait();

	private:
		EventHandle m_Handle;
	};
}

#endif // CORE_TOOLS_THREADING_EVENT_IMPL_H
