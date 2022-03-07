///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 13:47)

#ifndef NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
#define NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ACE.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ACEMainManager : public BaseMainManagerImpl, public ACE_Main_Base
    {
    public:
        using ClassType = ACEMainManager;
        using ParentType = BaseMainManagerImpl;
        using InterfaceType = ACE_Main_Base;

    public:
        ACEMainManager() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void Run() noexcept override;

        NODISCARD int run_i(int argc, ACE_TCHAR** argv) noexcept override;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
