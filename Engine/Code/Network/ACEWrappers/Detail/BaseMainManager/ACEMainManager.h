///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:01)

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
