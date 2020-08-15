// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 13:45)

#include "Network/NetworkExport.h" 

#include "SockACEHandleSet.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

using std::make_shared;

#ifdef NETWORK_USE_ACE
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26490) 
Network::SockACEHandleSet
	::SockACEHandleSet()
	:ParentType{}, m_ACEHandleSet{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSet)

void Network::SockACEHandleSet
	::SetBit(ACEHandle handle)
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
	::Sync(ACEHandle maxHandle)
{
	NETWORK_CLASS_IS_VALID_9;

	m_ACEHandleSet.sync(maxHandle);
}

bool Network::SockACEHandleSet
	::IsSet(ACEHandle handle) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ACEHandleSet.is_set(handle) != 0;
}

void Network::SockACEHandleSet
	::ClearBit(ACEHandle handle)
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
	::GetACEHandleSet() const noexcept
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
#include STSTEM_WARNING_POP
#endif // NETWORK_USE_ACE