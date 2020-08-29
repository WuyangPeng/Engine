// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:12)

#ifndef CORE_TOOLS_THREADING_STD_MUTEX_H
#define CORE_TOOLS_THREADING_STD_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 

#include <mutex>

namespace CoreTools
{
	// 标准库锁是不可递归的。
	class CORE_TOOLS_HIDDEN_DECLARE StdMutex : public MutexImpl
	{
	public:
		using ClassType = StdMutex;
		using ParentType = MutexImpl;

	public:
		StdMutex() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Initialize() noexcept override;
		void Delete() noexcept override;
		void Enter() override;
		bool TryEnter() override;
		void Leave() override;

	private:
		std::mutex m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_STD_MUTEX_H