// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:06)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "BaseMainManagerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullMainManager : public BaseMainManagerImpl
    {
    public:
        using ClassType = NullMainManager;
        using ParentType = BaseMainManagerImpl;

    public:
        NullMainManager() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Run() noexcept override;

        void StopContext() noexcept override;
        bool IsContextStop() const noexcept override;
        void RestartContext() noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
