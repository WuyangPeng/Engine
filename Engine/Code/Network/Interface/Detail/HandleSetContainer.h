///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:51)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/HandleSet.h"

#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetContainer final
    {
    public:
        using ClassType = HandleSetContainer;

    public:
        HandleSetContainer(const ConfigurationStrategy& configurationStrategy, ACEHandleType acceptorHandle);
        ~HandleSetContainer() noexcept = default;
        HandleSetContainer(const HandleSetContainer& rhs) = delete;
        HandleSetContainer& operator=(const HandleSetContainer& rhs) = delete;
        HandleSetContainer(HandleSetContainer&& rhs) noexcept = delete;
        HandleSetContainer& operator=(HandleSetContainer&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD HandleSet GetCurrentHandleSet() const;
        void SetBit(ACEHandleType sockStreamHandle);
        void ClearBit(ACEHandleType sockStreamHandle);
        void ToNextIndex();

    private:
        using HandleSetGroup = std::vector<HandleSet>;

    private:
        void Init();
        void Expansion();

    private:
        ConfigurationStrategy configurationStrategy;
        ACEHandle acceptorHandle;
        HandleSetGroup handleSetGroup;
        int currentIndex;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H
