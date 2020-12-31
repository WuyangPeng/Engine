//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:41)

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

        [[nodiscard]] const char* GetInitialBufferedPtr() const noexcept final;
        [[nodiscard]] char* GetInitialBufferedPtr() noexcept final;

        [[nodiscard]] ImplPtr Clone() const final;

        [[nodiscard]] BuffBlockSize GetBuffBlockSize() const noexcept final;
        [[nodiscard]] int GetSize() const final;

        [[nodiscard]] ImplPtr Expansion(int count) const final;

    private:
        void Resize(int count);

    private:
        std::vector<char> m_Buffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_VECTOR_BUFFER_H
