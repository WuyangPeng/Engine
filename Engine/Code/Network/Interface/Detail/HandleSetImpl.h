///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:52)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetImpl
    {
    public:
        using ClassType = HandleSetImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = HandleSetFactory;

    public:
        HandleSetImpl() noexcept = default;
        virtual ~HandleSetImpl() noexcept = default;
        HandleSetImpl(const HandleSetImpl& rhs) noexcept = default;
        HandleSetImpl& operator=(const HandleSetImpl& rhs) noexcept = default;
        HandleSetImpl(HandleSetImpl&& rhs) noexcept = default;
        HandleSetImpl& operator=(HandleSetImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void SetBit(ACEHandleType handle) = 0;
        NODISCARD virtual int64_t GetMaxSet() const = 0;
        NODISCARD virtual SockFdSet* GetFdSet() = 0;
        virtual void Sync(ACEHandleType maxHandle) = 0;
        NODISCARD virtual bool IsSet(ACEHandleType handle) const = 0;
        virtual void ClearBit(ACEHandleType handle) = 0;

        NODISCARD virtual ImplTypeSharedPtr Clone() const = 0;

        NODISCARD virtual const ACEHandleSet& GetACEHandleSet() const = 0;

        NODISCARD virtual bool IsFdSetFull() const = 0;
        NODISCARD virtual int IsFdSetCount() const = 0;

        NODISCARD virtual bool Select(int width) = 0;

        NODISCARD bool IsFdSetCountIsOne() const;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H
