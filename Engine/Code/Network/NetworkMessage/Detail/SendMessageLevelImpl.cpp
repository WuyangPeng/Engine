// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 16:29)

#include "Network/NetworkExport.h"

#include "SendMessageLevelImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::const_pointer_cast;

Network::SendMessageLevelImpl
	::SendMessageLevelImpl(int messageMaxSize)
	:m_TopLevel{}, m_MessageMaxSize{ messageMaxSize }, m_CurrentSize{ 0 }
{
	if (m_MessageMaxSize <= 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���û�������СС���㣡"));
	}

	NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::SendMessageLevelImpl
	::IsValid() const noexcept
{
	if (m_CurrentSize <= m_MessageMaxSize)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Network::SendMessageLevelImpl
	::GetTopLevelSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_TopLevel.size());
}

const Network::ConstMessageInterfaceSharedPtr Network::SendMessageLevelImpl
	::operator[](int index) const
{
	NETWORK_CLASS_IS_VALID_CONST_1;
	NETWORK_ASSERTION_0(0 <= index && index < GetTopLevelSize(), "��������");

	return m_TopLevel[index];
}

Network::MessageInterfaceSharedPtr Network::SendMessageLevelImpl
	::operator[](int index)
{
	NETWORK_CLASS_IS_VALID_1;
	NETWORK_ASSERTION_0(0 <= index && index < GetTopLevelSize(), "��������");

	return std::const_pointer_cast<MessageInterface>(static_cast<const ClassType&>(*this)[index]);
}

void Network::SendMessageLevelImpl
	::Insert(const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_1;

	if (m_MessageMaxSize < m_CurrentSize + message->GetStreamingSize())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��Ϣ�������㣡"));
	}
	else
	{
		m_TopLevel.push_back(message);
		m_CurrentSize += message->GetStreamingSize();
	}
}

int Network::SendMessageLevelImpl
	::GetRemainingSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_MessageMaxSize - m_CurrentSize;
}

int Network::SendMessageLevelImpl
	::GetCurrentSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_CurrentSize;
}

void Network::SendMessageLevelImpl
	::Clear()
{
	NETWORK_CLASS_IS_VALID_1;

	m_TopLevel.clear();
	m_CurrentSize = 0;
}



