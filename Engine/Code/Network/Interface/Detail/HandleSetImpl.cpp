// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:09)

#include "Network/NetworkExport.h" 

#include "HandleSetImpl.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  
#include "CoreTools/Contract/Noexcept.h"

using std::make_shared;

Network::HandleSetImpl
	::HandleSetImpl() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::HandleSetImpl
	::~HandleSetImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetImpl)

void Network::HandleSetImpl ::SetBit([[maybe_unused]] ACEHandle handle)
{
	NETWORK_CLASS_IS_VALID_9;

	 

	CoreTools::DisableNoexcept();
}

int64_t Network::HandleSetImpl
	::GetMaxSet() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	CoreTools::DisableNoexcept();

	return 0;
}

Network::SockFdSet* Network::HandleSetImpl
	::GetFdSet()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°fdset ß∞‹£°"s));
}

void Network::HandleSetImpl ::Sync([[maybe_unused]] ACEHandle maxHandle)
{
	NETWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

 
}

bool Network::HandleSetImpl ::IsSet([[maybe_unused]] ACEHandle handle) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	 

	CoreTools::DisableNoexcept();

	return false;
}

void Network::HandleSetImpl ::ClearBit([[maybe_unused]] ACEHandle handle)
{
	NETWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	 
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

	THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°ACEHandleSet ß∞‹£°"s));
}

bool Network::HandleSetImpl
	::IsFdSetFull() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	CoreTools::DisableNoexcept();

	return true;
}

int Network::HandleSetImpl
	::IsFdSetCount() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	CoreTools::DisableNoexcept();

	return 0;
}

bool Network::HandleSetImpl ::Select([[maybe_unused]] int width)
{
	NETWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return false;
}

bool Network::HandleSetImpl
	::IsFdSetCountIsOne() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return IsFdSetCount() == 1;
}

