/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:32)

#ifndef NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
#define NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ACE.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceMainManager final :
    public BaseMainManagerImpl,
    public ACE_Main_Base
    {
    public:
        using ClassType = AceMainManager;
        using ParentType = BaseMainManagerImpl;
        using InterfaceType = ACE_Main_Base;

    public:
        AceMainManager() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void Run() noexcept override;

        NODISCARD int run_i(int argc, ACE_TCHAR** argv) noexcept override;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_MAIN_MANAGER_H
