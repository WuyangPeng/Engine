//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:03)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetImpl
    {
    public:
        using ClassType = HandleSetImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;

    public:
        HandleSetImpl() noexcept = default;
        virtual ~HandleSetImpl() noexcept = default;
        HandleSetImpl(const HandleSetImpl&) = default;
        HandleSetImpl& operator=(const HandleSetImpl&) = default;
        HandleSetImpl(HandleSetImpl&&) noexcept = default;
        HandleSetImpl& operator=(HandleSetImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void SetBit(ACEHandle handle);
        [[nodiscard]] virtual int64_t GetMaxSet() const;
        [[nodiscard]] virtual SockFdSet* GetFdSet();
        virtual void Sync(ACEHandle maxHandle);
        [[nodiscard]] virtual bool IsSet(ACEHandle handle) const;
        virtual void ClearBit(ACEHandle handle);

        [[nodiscard]] virtual ImplTypePtr Clone() const;

        [[nodiscard]] virtual const ACEHandleSet& GetACEHandleSet() const;

        [[nodiscard]] virtual bool IsFdSetFull() const;
        [[nodiscard]] virtual int IsFdSetCount() const;

        [[nodiscard]] virtual bool Select(int width);

        [[nodiscard]] bool IsFdSetCountIsOne() const;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H
