// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:06)

#ifndef CORE_TOOLS_THREADING_BOOST_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 

#include "System/Helper/PragmaWarning/Mutex.h" 

namespace CoreTools
{
	// boost锁是不可递归的。重入会死锁，而不是抛出异常。
	class CORE_TOOLS_HIDDEN_DECLARE BoostMutex : public MutexImpl
	{
	public:
		using ClassType = BoostMutex;
		using ParentType = MutexImpl;

	public:
		BoostMutex();
		virtual ~BoostMutex();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void Initialize() override;
		void Delete() override;
		void Enter() override;
		bool TryEnter() override;
		void Leave() override;

	private:
		boost::mutex m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_BOOST_MUTEX_H