// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:12)

#ifndef CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H
#define CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 

#include <mutex>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE StdRecursiveMutex : public MutexImpl
	{
	public:
		using ClassType = StdRecursiveMutex;
		using ParentType = MutexImpl;

	public:
		StdRecursiveMutex() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Initialize() noexcept override;
		void Delete() noexcept override;
		void Enter() override;
		bool TryEnter() noexcept override;
		void Leave() override;

	private:
		std::recursive_mutex m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H