//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:04)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetIteratorFactory final
    {
    public:
        using ClassType = HandleSetIteratorFactory;
        using ImplType = HandleSetIteratorImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        HandleSetIteratorFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_FACTORY_H
