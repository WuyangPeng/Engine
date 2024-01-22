/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:17)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H

#include "Network/NetworkDll.h"

#include "MultipleMessageContainer.h"

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    requires(std::is_enum_v<E>)
    class MultipleMessageContainerGroup final
    {
    public:
        using ClassType = MultipleMessageContainerGroup<E, ByteType, Types...>;

        using MessageType = MultipleMessageContainer<E, ByteType, Types...>;
        using GroupType = std::vector<MessageType>;
        using GroupConstIter = typename GroupType::const_iterator;

    public:
        MultipleMessageContainerGroup() noexcept;

        explicit MultipleMessageContainerGroup(const GroupType& group);

        CLASS_INVARIANT_DECLARE;

        void Load(MessageSource& source);
        void Save(MessageTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetSize() const;

        NODISCARD MessageType GetValue(int index) const;

        NODISCARD GroupConstIter begin() const noexcept;
        NODISCARD GroupConstIter end() const noexcept;

    private:
        GroupType group;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
