// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 17:19)

#include "Network/NetworkExport.h" 

#include "HandleSetImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

using std::make_shared;

Network::HandleSetImpl
	::HandleSetImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::HandleSetImpl
	::~HandleSetImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network,HandleSetImpl)

void Network::HandleSetImpl
	::SetBit( ACEHandle handle )
{
	NETWORK_CLASS_IS_VALID_9;
	
	SYSTEM_UNUSED_ARG(handle);
}

int64_t Network::HandleSetImpl
	::GetMaxSet() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}

Network::SockFdSet* Network::HandleSetImpl
	::GetFdSet()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°fdset ß∞‹£°"));
}

void Network::HandleSetImpl
	::Sync( ACEHandle maxHandle )
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(maxHandle);
}

bool Network::HandleSetImpl
	::isSet( ACEHandle handle ) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(handle);

	return false;
}

void Network::HandleSetImpl
	::ClearBit( ACEHandle handle )
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(handle);
}

Network::HandleSetImpl::ImplTypePtr Network::HandleSetImpl
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::HandleSetImpl
	::GetACEHandleSet() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°ACEHandleSet ß∞‹£°"));
}

bool Network::HandleSetImpl
	::IsFdSetFull() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return true;
}

int Network::HandleSetImpl
	::IsFdSetCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}

bool Network::HandleSetImpl
	::Select(int width)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(width);

	return false;
}

bool Network::HandleSetImpl
	::IsFdSetCountIsOne() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return IsFdSetCount() == 1;
}

