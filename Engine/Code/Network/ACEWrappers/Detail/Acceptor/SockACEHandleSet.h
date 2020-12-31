//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 14:31)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "Network/Interface/Detail/HandleSetImpl.h"

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
        [[nodiscard]] int64_t GetMaxSet() const override;
        [[nodiscard]] SockFdSet* GetFdSet() override;
        void Sync(ACEHandle maxHandle) override;
        [[nodiscard]] bool IsSet(ACEHandle handle) const override;
        void ClearBit(ACEHandle handle) override;
        [[nodiscard]] bool IsFdSetFull() const override;
        [[nodiscard]] int IsFdSetCount() const override;

        [[nodiscard]] ImplTypePtr Clone() const override;

        [[nodiscard]] const ACEHandleSet& GetACEHandleSet() const noexcept override;

        [[nodiscard]] bool Select(int width) override;

    private:
        ACEHandleSet m_ACEHandleSet;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
