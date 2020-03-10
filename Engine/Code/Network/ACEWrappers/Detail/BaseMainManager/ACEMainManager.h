// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 20:17)
#ifndef NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
#define NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#include <ace/OS_main.h>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ACEMainManager : public BaseMainManagerImpl, public ACE_Main_Base
	{
	public:
		using ClassType = ACEMainManager;
		using ParentType = BaseMainManagerImpl;
		using InterfaceType = ACE_Main_Base;

	public:
		ACEMainManager();
		virtual ~ACEMainManager();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
	public:	
		virtual void Run() override;

		virtual int run_i(int argc, ACE_TCHAR** argv) override;
	};	
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
