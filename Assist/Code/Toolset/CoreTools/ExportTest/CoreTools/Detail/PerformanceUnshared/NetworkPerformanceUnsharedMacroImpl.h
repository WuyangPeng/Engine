///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 23:47)

#ifndef EXPORT_TEST_NETWORK_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_NETWORK_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = NetworkPerformanceUnsharedMacroImpl;

    public:
        explicit NetworkPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_NETWORK_PERFORMANCE_UNSHARED_MACRO_IMPL_H