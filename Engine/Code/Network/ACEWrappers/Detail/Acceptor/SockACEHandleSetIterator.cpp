// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 20:20)

#include "Network/NetworkExport.h" 

#include "SockACEHandleSetIterator.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

#ifdef NETWORK_USE_ACE

Network::SockACEHandleSetIterator
	::SockACEHandleSetIterator(const ACEHandleSet& handleSet)
	:ParentType{},m_ACEHandleSetIter{ handleSet }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}
 
Network::SockACEHandleSetIterator
	::~SockACEHandleSetIterator()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSetIterator)

Network::ACEHandle Network::SockACEHandleSetIterator
	::operator()()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ACEHandleSetIter();
}

#endif // NETWORK_USE_ACE