// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:12)

#ifndef CORE_TOOLS_THREADING_NULL_MUTEX_H
#define CORE_TOOLS_THREADING_NULL_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE NullMutex : public MutexImpl
	{
	public:
		using ClassType = NullMutex;
		using ParentType = MutexImpl;

	public:
		NullMutex() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Initialize() noexcept override;
		void Delete() noexcept override;
		void Enter() noexcept override;
		bool TryEnter() noexcept override;
		void Leave() noexcept override;
	};
}

#endif // CORE_TOOLS_THREADING_NULL_MUTEX_H