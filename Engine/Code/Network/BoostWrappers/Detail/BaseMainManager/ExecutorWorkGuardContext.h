// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 13:07)


#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <boost/noncopyable.hpp> 

#include "System/Helper/PragmaWarning/ExecutorWorkGuard.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContext : private boost::noncopyable
	{
	public:
		using ClassType = ExecutorWorkGuardContext;

	public:
		ExecutorWorkGuardContext();

		CLASS_INVARIANT_DECLARE;

	public:
		void Run();

		IOContextType& GetIOContext();
		void PostStopContext();
		void DispatchStopContext();
		bool IsContextStop() const;
		void RestartContext();

	private:
		using ExecutorWorkGuard = boost::asio::executor_work_guard<IOContextType::executor_type>;

	private:
		IOContextType m_IOContext;
		ExecutorWorkGuard m_Work;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
