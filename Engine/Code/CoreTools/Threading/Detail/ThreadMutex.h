// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:13)

#ifndef CORE_TOOLS_THREADING_THREAN_MUTEX_H
#define CORE_TOOLS_THREADING_THREAN_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/MutexUsing.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ThreadMutex : public MutexImpl
	{
	public:
		using ClassType = ThreadMutex;
		using ParentType = MutexImpl;
		using MutexType = System::MutexType;

	public:
		ThreadMutex();
		virtual ~ThreadMutex();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void Initialize() override;
		virtual void Delete() override;
		virtual void Enter() override;
		virtual bool TryEnter() override;
		virtual void Leave() override;

	private:
		MutexType m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_THREAN_MUTEX_H
