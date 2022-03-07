///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 13:46)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/HandleSetImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockACEHandleSet : public HandleSetImpl
    {
    public:
        using ClassType = SockACEHandleSet;
        using ParentType = HandleSetImpl;

    public:
        SockACEHandleSet() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetBit(ACEHandle handle) override;
        NODISCARD int64_t GetMaxSet() const override;
        NODISCARD SockFdSet* GetFdSet() override;
        void Sync(ACEHandle maxHandle) override;
        NODISCARD bool IsSet(ACEHandle handle) const override;
        void ClearBit(ACEHandle handle) override;
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
