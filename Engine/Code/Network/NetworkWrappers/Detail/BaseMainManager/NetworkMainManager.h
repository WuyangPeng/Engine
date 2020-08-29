// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 16:29)

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
                NetworkMainManager()  ;
		  ~NetworkMainManager() noexcept;
		  
		  NetworkMainManager(const NetworkMainManager&) = default;
		NetworkMainManager& operator=(const NetworkMainManager&) = default;
		NetworkMainManager(NetworkMainManager&&) = default;
		NetworkMainManager& operator=(NetworkMainManager&&) = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	public:
		  void Run() noexcept override;

	private:
		void Init()  ;
		void Release() noexcept;
	};
}

#endif // NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H
