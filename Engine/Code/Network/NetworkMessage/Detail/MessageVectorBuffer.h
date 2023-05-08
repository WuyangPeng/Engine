///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 11:38)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H

#include "Network/NetworkDll.h"

#include "MessageBufferImpl.h"

#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageVectorBuffer final : public MessageBufferImpl
    {
    public:
        using ClassType = MessageVectorBuffer;
        using ParentType = MessageBufferImpl;

    public:
        MessageVectorBuffer(int count, ParserStrategy parserStrategy);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD const char* GetInitialBufferedPtr() const noexcept override;
        NODISCARD char* GetInitialBufferedPtr() noexcept override;

        NODISCARD ImplPtr Clone() const override;

        NODISCARD BuffBlockSize GetBuffBlockSize() const noexcept override;
        NODISCARD int GetSize() const override;

        NODISCARD ImplPtr Expansion(int count) const override;

    private:
        using BufferType = std::vector<char>;

    private:
        void Resize(int count);

    private:
        BufferType buffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H
