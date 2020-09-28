// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:11)

#include "Network/NetworkExport.h" 

#include "HandleSetIteratorImpl.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

Network::HandleSetIteratorImpl
	::HandleSetIteratorImpl() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::HandleSetIteratorImpl
	::~HandleSetIteratorImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIteratorImpl)

Network::ACEHandle Network::HandleSetIteratorImpl
	::operator()()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°æ‰±˙ ß∞‹£°"s));
}

