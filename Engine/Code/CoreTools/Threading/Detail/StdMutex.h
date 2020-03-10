// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:12)

#ifndef CORE_TOOLS_THREADING_STD_MUTEX_H
#define CORE_TOOLS_THREADING_STD_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 

#include <mutex>

namespace CoreTools
{
	// ��׼�����ǲ��ɵݹ�ġ�
	class CORE_TOOLS_HIDDEN_DECLARE StdMutex : public MutexImpl
	{
	public:
		using ClassType = StdMutex;
		using ParentType = MutexImpl;

	public:
		StdMutex();
		virtual ~StdMutex();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void Initialize() override;
		virtual void Delete() override;
		virtual void Enter() override;
		virtual bool TryEnter() override;
		virtual void Leave() override;

	private:
		std::mutex m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_STD_MUTEX_H