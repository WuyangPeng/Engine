// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:54)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "BaseMainManagerImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NullMainManager : public BaseMainManagerImpl
	{
	public:
		using ClassType = NullMainManager;
		using ParentType = BaseMainManagerImpl;

	public:
		NullMainManager();
		virtual ~NullMainManager();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;	

		virtual void Run() override;

		virtual void StopContext() override;
		virtual bool IsContextStop() const override;
		virtual void RestartContext() override;
	};	
}

#endif // NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
