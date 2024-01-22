/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:32)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/HandleSetImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAceHandleSet final : public HandleSetImpl
    {
    public:
        using ClassType = SockAceHandleSet;
        using ParentType = HandleSetImpl;

    public:
        SockAceHandleSet() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetBit(ACEHandleType handle) override;
        NODISCARD int64_t GetMaxSet() const override;
        NODISCARD SockFdSet* GetFdSet() override;
        void Sync(ACEHandleType maxHandle) override;
        NODISCARD bool IsSet(ACEHandleType handle) const override;
        void ClearBit(ACEHandleType handle) override;
        NODISCARD bool IsFdSetFull() const override;
        NODISCARD int IsFdSetCount() const override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

        NODISCARD const ACEHandleSet& GetACEHandleSet() const noexcept override;

        NODISCARD bool Select(int width) override;

    private:
        ACEHandleSet aceHandleSet;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
