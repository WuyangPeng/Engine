// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/02 10:16)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/BaseMainManagerImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NetworkMainManager : public BaseMainManagerImpl
	{
	public:
		using ClassType = NetworkMainManager;
		using ParentType = BaseMainManagerImpl;

	public:
		NetworkMainManager();
		virtual ~NetworkMainManager();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
	public:	
		virtual void Run() override;

	private:
		void Init();
		void Release();
	};	
}

#endif // NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H
