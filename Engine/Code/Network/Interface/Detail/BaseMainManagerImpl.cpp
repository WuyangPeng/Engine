// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 10:58)

#include "Network/NetworkExport.h"

#include "BaseMainManagerImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::BaseMainManagerImpl
	::BaseMainManagerImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BaseMainManagerImpl
	::~BaseMainManagerImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManagerImpl)

Network::IOContextType& Network::BaseMainManagerImpl
	::GetIOContext()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"));
}

void Network::BaseMainManagerImpl
	::StopContext()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"));
}

bool Network::BaseMainManagerImpl
	::IsContextStop() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"));
}

void Network::BaseMainManagerImpl
	::RestartContext()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"));
}

