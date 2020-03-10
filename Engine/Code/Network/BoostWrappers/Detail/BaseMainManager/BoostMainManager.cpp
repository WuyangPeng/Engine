// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 13:09)


#include "Network/NetworkExport.h"

#include "BoostMainManager.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::BoostMainManager
	::BoostMainManager()
	:ParentType{}, m_ExecutorWorkGuardContext{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostMainManager
	::~BoostMainManager()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostMainManager)

void Network::BoostMainManager
	::Run()
{
	NETWORK_CLASS_IS_VALID_9;

	m_ExecutorWorkGuardContext.Run();
}

Network::IOContextType& Network::BoostMainManager
	::GetIOContext()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ExecutorWorkGuardContext.GetIOContext();
}

void Network::BoostMainManager
	::StopContext()
{
	NETWORK_CLASS_IS_VALID_9;

	m_ExecutorWorkGuardContext.PostStopContext();
}

bool Network::BoostMainManager
	::IsContextStop() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ExecutorWorkGuardContext.IsContextStop();
}

void Network::BoostMainManager
	::RestartContext()
{
	NETWORK_CLASS_IS_VALID_9;

	m_ExecutorWorkGuardContext.RestartContext();
}

void Network::BoostMainManager
	::DispatchStopContext()
{
	m_ExecutorWorkGuardContext.DispatchStopContext();
}
