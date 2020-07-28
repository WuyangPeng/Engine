// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:06)

#ifndef CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 
#include "System/Helper/PragmaWarning/RecursiveMutex.h" 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BoostRecursiveMutex : public MutexImpl
	{
	public:
		using ClassType = BoostRecursiveMutex;
		using ParentType = MutexImpl;

	public:
		BoostRecursiveMutex();
		virtual ~BoostRecursiveMutex();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void Initialize() override;
		void Delete() override;
		void Enter() override;
		bool TryEnter() override;
		void Leave() override;

	private:
		boost::recursive_mutex m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H