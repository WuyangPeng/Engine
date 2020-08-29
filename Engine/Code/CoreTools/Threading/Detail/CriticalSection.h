// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:07)

// �ٽ�����
#ifndef CORE_TOOLS_THREADING_CRITICAL_SECTION_H
#define CORE_TOOLS_THREADING_CRITICAL_SECTION_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/CriticalSectionUsing.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CriticalSection : public MutexImpl
	{
	public:
		using ClassType = CriticalSection;
		using ParentType = MutexImpl;
		using ThreadingCriticalSection = System::ThreadingCriticalSection;

	public:
		CriticalSection() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Initialize() override;
		void Delete() noexcept override;
		void Enter() noexcept override;
		bool TryEnter() noexcept override;
		void Leave() noexcept override;

	private:
		ThreadingCriticalSection m_CriticalSection;
	};
}

#endif // CORE_TOOLS_THREADING_CRITICAL_SECTION_H