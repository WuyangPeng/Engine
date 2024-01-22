/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:23)

#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContext
    {
    public:
        using ClassType = ExecutorWorkGuardContext;

    public:
        explicit ExecutorWorkGuardContext(CoreTools::DisableNotThrow disableNotThrow);
        ~ExecutorWorkGuardContext() noexcept = default;
        ExecutorWorkGuardContext(const ExecutorWorkGuardContext& rhs) = delete;
        ExecutorWorkGuardContext& operator=(const ExecutorWorkGuardContext& rhs) = delete;
        ExecutorWorkGuardContext(ExecutorWorkGuardContext&& rhs) noexcept = delete;
        ExecutorWorkGuardContext& operator=(ExecutorWorkGuardContext&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    public:
        void Run();

        NODISCARD IoContextType& GetContext() noexcept;
        void PostStopContext();
        void DispatchStopContext();
        NODISCARD bool IsContextStop() const;
        void RestartContext();

    private:
        using ExecutorWorkGuard = boost::asio::executor_work_guard<IoContextType::executor_type>;

    private:
        IoContextType ioContext;
        ExecutorWorkGuard work;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
