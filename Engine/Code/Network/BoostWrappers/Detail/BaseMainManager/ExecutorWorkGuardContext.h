///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 14:23)

#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ExecutorWorkGuard.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContext
    {
    public:
        using ClassType = ExecutorWorkGuardContext;

    public:
        explicit ExecutorWorkGuardContext(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
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
