//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 16:27)

#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ExecutorWorkGuard.h"
#include "Network/Interface/NetworkInternalFwd.h"

#include <boost/noncopyable.hpp>

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

        [[nodiscard]] IOContextType& GetIOContext() noexcept;
        void PostStopContext();
        void DispatchStopContext();
        [[nodiscard]] bool IsContextStop() const;
        void RestartContext();

    private:
        using ExecutorWorkGuard = boost::asio::executor_work_guard<IOContextType::executor_type>;

    private:
        IOContextType m_IOContext;
        ExecutorWorkGuard m_Work;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
