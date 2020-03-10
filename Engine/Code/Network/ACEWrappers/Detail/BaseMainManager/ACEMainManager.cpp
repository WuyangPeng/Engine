// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/01 20:20)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

#include "ACEMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "System/Helper/UnusedMacro.h"

Network::ACEMainManager
	::ACEMainManager() 
	:ParentType{}, InterfaceType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACEMainManager
	::~ACEMainManager()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACEMainManager)

void Network::ACEMainManager
	::Run()
{
	NETWORK_CLASS_IS_VALID_9;
}

int Network::ACEMainManager
	::run_i(int argc , ACE_TCHAR** argv)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(argc);
	SYSTEM_UNUSED_ARG(argv);

	return 0;
}

#endif // NETWORK_USE_ACE

