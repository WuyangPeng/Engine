//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:35)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H

#include "Network/NetworkDll.h"

#include "MessageBufferImpl.h"
#include "System/Helper/EnumCast.h"

#include <array>

namespace Network
{
    template <BuffBlockSize buffBlockSize>
    class MessageArrayBuffer final : public MessageBufferImpl
    {
    public:
        using ClassType = MessageArrayBuffer<buffBlockSize>;
        using ParentType = MessageBufferImpl;

    public:
        explicit MessageArrayBuffer(ParserStrategy parserStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] const char* GetInitialBufferedPtr() const noexcept final;
        [[nodiscard]] char* GetInitialBufferedPtr() noexcept final;

        [[nodiscard]] ImplPtr Clone() const final;

        [[nodiscard]] BuffBlockSize GetBuffBlockSize() const noexcept final;
        [[nodiscard]] int GetSize() const noexcept final;

        [[nodiscard]] ImplPtr Expansion(int count) const final;

    private:
        std::array<char, System::EnumCastUnderlying(buffBlockSize)> m_Buffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H
