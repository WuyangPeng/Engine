// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 10:01)

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
		BaseMainManagerImpl() noexcept;
		virtual ~BaseMainManagerImpl();
		BaseMainManagerImpl(const BaseMainManagerImpl&) = default;
		BaseMainManagerImpl& operator=(const BaseMainManagerImpl&) = default;
		BaseMainManagerImpl(BaseMainManagerImpl&&) noexcept = default;
		BaseMainManagerImpl& operator=(BaseMainManagerImpl&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	public:
		virtual void Run() = 0;

		// ��boost��������Ĭ���׳��쳣��
		virtual IOContextType& GetIOContext();
		virtual void StopContext();
		virtual bool IsContextStop() const;
		virtual void RestartContext();
	};
}

#endif // NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
