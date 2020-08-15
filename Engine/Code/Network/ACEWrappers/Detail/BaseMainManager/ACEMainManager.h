// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:43)

#ifndef NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
#define NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#include "System/Helper/PragmaWarning/ACE.h"

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

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
		void Run() override;

		int run_i(int argc, ACE_TCHAR** argv) override;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
