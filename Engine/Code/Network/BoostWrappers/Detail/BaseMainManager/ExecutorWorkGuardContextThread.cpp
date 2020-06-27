// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:56)

#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContextThread.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::make_unique;

Network::ExecutorWorkGuardContextThread
	::ExecutorWorkGuardContextThread()
	:m_ExecutorWorkGuardContext{}, m_Thread{}
{
	InitThread();

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ExecutorWorkGuardContextThread
	::~ExecutorWorkGuardContextThread()
{
	NETWORK_SELF_CLASS_IS_VALID_9;

	JoinThreads();
}

CLASS_INVARIANT_STUB_DEFINE(Network, ExecutorWorkGuardContextThread)

Network::IOContextType& Network::ExecutorWorkGuardContextThread
	::GetIOContext()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ExecutorWorkGuardContext.GetIOContext();
}

void Network::ExecutorWorkGuardContextThread
	::StopContext()
{
	NETWORK_CLASS_IS_VALID_9;

	m_ExecutorWorkGuardContext.PostStopContext();

	JoinThreads();
}

bool Network::ExecutorWorkGuardContextThread
	::IsContextStop() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ExecutorWorkGuardContext.IsContextStop();
}

void Network::ExecutorWorkGuardContextThread
	::RestartContext()
{
	NETWORK_CLASS_IS_VALID_9;

	JoinThreads();

	m_ExecutorWorkGuardContext.RestartContext();

	InitThread();
}

// private
void Network::ExecutorWorkGuardContextThread
	::InitThread()
{
	m_Thread = make_unique<ThreadType>(&ExecutorWorkGuardContext::Run, &m_ExecutorWorkGuardContext);
}

// private
void Network::ExecutorWorkGuardContextThread
	::JoinThreads()
{
	if (m_Thread != nullptr)
	{
		m_Thread->join();

		m_Thread.reset();
	}
}
