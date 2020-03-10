// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 13:07)


#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContext.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/AsioPost.h"

using std::bind;
using std::exception;
using boost::asio::post;
using boost::system::system_error;
using CoreTools::Error;

Network::ExecutorWorkGuardContext
	::ExecutorWorkGuardContext()
	:m_IOContext{}, m_Work{ make_work_guard(m_IOContext) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ExecutorWorkGuardContext)

void Network::ExecutorWorkGuardContext
	::Run()
{
	NETWORK_CLASS_IS_VALID_9;

	for (;;)
	{
		try
		{
			m_IOContext.run();
			break;
		}
		catch (Error& error)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
				<< error
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
		catch (system_error& error)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
				<< error.what()
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
		catch (exception& error)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
				<< error.what()
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
		catch (...)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
				<< "Œ¥÷™¥ÌŒÛ\n"
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
	}
}

Network::IOContextType& Network::ExecutorWorkGuardContext
	::GetIOContext()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_IOContext;
}

void Network::ExecutorWorkGuardContext
	::PostStopContext()
{
	NETWORK_CLASS_IS_VALID_9;

	post(m_IOContext, bind(&IOContextType::stop, &m_IOContext));
}

bool Network::ExecutorWorkGuardContext
	::IsContextStop() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_IOContext.stopped();
}

void Network::ExecutorWorkGuardContext
	::RestartContext()
{
	NETWORK_CLASS_IS_VALID_9;

	m_IOContext.restart();
}

void Network::ExecutorWorkGuardContext
	::DispatchStopContext()
{
	m_IOContext.stop();
}
