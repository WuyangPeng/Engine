// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 20:19)

#include "Network/NetworkExport.h" 

#include "SockACEHandleSet.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

using std::make_shared;

#ifdef NETWORK_USE_ACE

Network::SockACEHandleSet
	::SockACEHandleSet()
	:ParentType{}, m_ACEHandleSet{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockACEHandleSet
	::~SockACEHandleSet()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network,SockACEHandleSet)

void Network::SockACEHandleSet
	::SetBit( ACEHandle handle )
{
	NETWORK_CLASS_IS_VALID_9;

	m_ACEHandleSet.set_bit(handle);
}

int64_t Network::SockACEHandleSet
	::GetMaxSet() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return reinterpret_cast<int64_t>(m_ACEHandleSet.max_set());
}

Network::SockFdSet* Network::SockACEHandleSet
	::GetFdSet()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ACEHandleSet.fdset();
}

void Network::SockACEHandleSet
	::Sync( ACEHandle maxHandle )
{
	NETWORK_CLASS_IS_VALID_9;

	m_ACEHandleSet.sync(maxHandle);
}

bool Network::SockACEHandleSet
	::isSet( ACEHandle handle ) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ACEHandleSet.is_set(handle) != 0;
}

void Network::SockACEHandleSet
	::ClearBit( ACEHandle handle )
{
	NETWORK_CLASS_IS_VALID_9;

	m_ACEHandleSet.clr_bit(handle);
}

Network::SockACEHandleSet::ImplTypePtr Network::SockACEHandleSet
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::SockACEHandleSet
	::GetACEHandleSet() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ACEHandleSet;
}

bool Network::SockACEHandleSet
	::IsFdSetFull() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	if (FD_SETSIZE <= m_ACEHandleSet.num_set())
		return true;
	else
		return false;
}

int Network::SockACEHandleSet
	::IsFdSetCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ACEHandleSet.num_set();
}

bool Network::SockACEHandleSet
	::Select(int width)
{
	NETWORK_CLASS_IS_VALID_9;

	if (0 < ACE::select(width, m_ACEHandleSet))
		return true;
	else
		return false;
}

#endif // NETWORK_USE_ACE