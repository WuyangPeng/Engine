// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/21 09:55)


#ifndef NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
#define NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BaseMainManagerImpl
	{
	public:
		using ClassType = BaseMainManagerImpl;		

	public:
		BaseMainManagerImpl();
		virtual ~BaseMainManagerImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;		
		
	public:	
		virtual void Run() = 0;

		// 非boost主管理类默认抛出异常。
		virtual IOContextType& GetIOContext();
		virtual void StopContext();
		virtual bool IsContextStop() const;
		virtual void RestartContext();
	};	
}

#endif // NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
