///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 11:25)

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

        NODISCARD const char* GetInitialBufferedPtr() const noexcept final;
        NODISCARD char* GetInitialBufferedPtr() noexcept final;

        NODISCARD ImplPtr Clone() const final;

        NODISCARD BuffBlockSize GetBuffBlockSize() const noexcept final;
        NODISCARD int GetSize() const final;

        NODISCARD ImplPtr Expansion(int count) const final;

    private:
        using BufferType = std::vector<char>;

    private:
        void Resize(int count);

    private:
        BufferType buffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H
