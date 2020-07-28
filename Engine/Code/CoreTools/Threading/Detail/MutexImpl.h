// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:07)

#ifndef CORE_TOOLS_THREADING_MUTEX_IMPL_H
#define CORE_TOOLS_THREADING_MUTEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE MutexImpl
	{
	public:
		using ClassType = MutexImpl;

	public:
		MutexImpl() noexcept;
		virtual ~MutexImpl() noexcept;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Initialize() = 0;
		virtual void Delete() = 0;
		virtual void Enter() = 0;
		virtual bool TryEnter() = 0;
		virtual void Leave() = 0;
	};
}

#endif // CORE_TOOLS_THREADING_MUTEX_IMPL_H
