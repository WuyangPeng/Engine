//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 19:53)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/HandleSet.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetContainer final : private boost::noncopyable
    {
    public:
        using ClassType = HandleSetContainer;

    public:
        HandleSetContainer(const ConfigurationStrategy& configurationStrategy, ACEHandle acceptorHandle);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const HandleSet GetCurrentHandleSet() const noexcept;
        void SetBit(ACEHandle sockStreamHandle);
        void ClearBit(ACEHandle sockStreamHandle);
        void ToNextIndex();

    private:
        using HandleSetGroup = std::vector<HandleSet>;

    private:
        void Init();
        void Expansion();

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
        ACEHandle m_AcceptorHandle;
        HandleSetGroup m_HandleSetGroup;
        int m_CurrentIndex;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_CONTAINER_H
