// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:54)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/HandleSet.h"

#include <vector>

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE HandleSetContainer  
	{
	public:
		using ClassType = HandleSetContainer;

	public:
		HandleSetContainer(const ConfigurationStrategy& configurationStrategy, ACEHandle acceptorHandle);
	 
		CLASS_INVARIANT_DECLARE;

		const HandleSet GetCurrentHandleSet() const;
		void SetBit(ACEHandle sockStreamHandle);
		void ClearBit(ACEHandle sockStreamHandle);
		void ToNextIndex();

	private:
		using HandleSetGroup = std::vector<HandleSet>;

	private:
		void Init();
		void Expansion();
		 	 
	private:	
		ConfigurationStrategy m_ConfigurationStrategy;		
		ACEHandle m_AcceptorHandle;
		HandleSetGroup m_HandleSetGroup;
		int m_CurrentIndex;
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H
