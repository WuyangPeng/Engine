// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:29)

#include "Network/NetworkExport.h"

#include "ReceiveMessageLevelImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::make_pair;

Network::ReceiveMessageLevelImpl
	::ReceiveMessageLevelImpl() noexcept
	:m_TopLevel{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReceiveMessageLevelImpl)

int Network::ReceiveMessageLevelImpl
	::GetTopLevelSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_TopLevel.size());
}

const Network::ConstMessageInterfaceSharedPtr Network::ReceiveMessageLevelImpl
	::operator[](int index) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;
	NETWORK_ASSERTION_0(0 <= index && index < GetTopLevelSize(), "À˜“˝¥ÌŒÛ£°");

	return m_TopLevel.at(index);
}

void Network::ReceiveMessageLevelImpl
	::Insert(const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	m_TopLevel.push_back(message);
}

Network::ReceiveMessageLevelImpl::MessageContainerConstIter Network::ReceiveMessageLevelImpl
	::begin() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_TopLevel.begin();
}

Network::ReceiveMessageLevelImpl::MessageContainerConstIter Network::ReceiveMessageLevelImpl
	::end() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_TopLevel.end();
}

