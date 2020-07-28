// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:06)

#ifndef CORE_TOOLS_THREADING_BOOST_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h" 

#include "System/Helper/PragmaWarning/Mutex.h" 

namespace CoreTools
{
	// boost���ǲ��ɵݹ�ġ�������������������׳��쳣��
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