// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/21 13:09)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContext.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostMainManager : public BaseMainManagerImpl
	{
	public:
		using ClassType = BoostMainManager;
		using ParentType = BaseMainManagerImpl;

	public:
		BoostMainManager();
		virtual ~BoostMainManager();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
		virtual void Run() override;

		virtual IOContextType& GetIOContext() override;
		virtual void StopContext() override;
		virtual bool IsContextStop() const override;
		virtual void RestartContext() override;

	protected:
		void DispatchStopContext();

	private:
		ExecutorWorkGuardContext m_ExecutorWorkGuardContext;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H
