///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:20)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H

#include "Network/NetworkDll.h"

#include "MessageBufferImpl.h"
#include "System/Helper/EnumCast.h"

#include <array>

namespace Network
{
    template <BuffBlockSize Size>
    class MessageArrayBuffer final : public MessageBufferImpl
    {
    public:
        using ClassType = MessageArrayBuffer<Size>;
        using ParentType = MessageBufferImpl;

    public:
        explicit MessageArrayBuffer(ParserStrategy parserStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD const char* GetInitialBufferedPtr() const noexcept override;
        NODISCARD char* GetInitialBufferedPtr() noexcept override;

        NODISCARD ImplPtr Clone() const override;

        NODISCARD BuffBlockSize GetBuffBlockSize() const noexcept override;
        NODISCARD int GetSize() const noexcept override;

        NODISCARD ImplPtr Expansion(int count) const override;

    private:
        using BufferType = std::array<char, System::EnumCastUnderlying(Size)>;

    private:
        BufferType buffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_H
