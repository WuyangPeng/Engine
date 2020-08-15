// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:46)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

#include "ACEMainManager.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26487) 
#include SYSTEM_WARNING_DISABLE(26440) 
Network::ACEMainManager
	::ACEMainManager()
	:ParentType{}, InterfaceType{}
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
	::run_i(int argc, ACE_TCHAR** argv)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(argc);
	SYSTEM_UNUSED_ARG(argv);

	return 0;
}
#include STSTEM_WARNING_POP
#endif // NETWORK_USE_ACE

