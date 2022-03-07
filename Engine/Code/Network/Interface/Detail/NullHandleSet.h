///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 13:52)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_NULL_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "HandleSetImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullHandleSet final : public HandleSetImpl
    {
    public:
        using ClassType = NullHandleSet;
        using ParentType = HandleSetImpl;

    public:
        NullHandleSet() noexcept = default;

        CLASS_INVARIANT_FINAL_DECLARE;

        void SetBit(ACEHandle handle) noexcept override;
        NODISCARD int64_t GetMaxSet() const noexcept override;
        NODISCARD SockFdSet* GetFdSet() override;
        void Sync(ACEHandle maxHandle) noexcept override;
        NODISCARD bool IsSet(ACEHandle handle) const noexcept override;
        void ClearBit(ACEHandle handle) noexcept override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

        NODISCARD const ACEHandleSet& GetACEHandleSet() const override;

        NODISCARD bool IsFdSetFull() const noexcept override;
        NODISCARD int IsFdSetCount() const noexcept override;

        NODISCARD bool Select(int width) noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_HANDLE_SET_H
