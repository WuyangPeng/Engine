// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/01 16:54)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_FACTORY_H

#include "Network/NetworkDll.h" 

#include <memory>

namespace Network
{	
	class HandleSetImpl;
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE HandleSetFactory
	{
	public:
		using ClassType = HandleSetFactory;
		using ImplType = HandleSetImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		HandleSetFactory ();	 

		CLASS_INVARIANT_DECLARE;
		 	 
		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_FACTORY_H
