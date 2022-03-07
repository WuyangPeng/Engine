///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 15:55)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "Network/Helper/StreamMacro.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageInterface
    {
    public:
        using ClassType = MessageInterface;
        CORE_TOOLS_SHARED_PTR_DECLARE(MessageInterface);
        using Rtti = CoreTools::Rtti;
        using FactoryFunction = MessageInterfaceSharedPtr (*)(MessageSource& stream, int64_t messageID);

    public:
        explicit MessageInterface(int64_t messageID) noexcept;
        virtual ~MessageInterface() noexcept = 0;
        MessageInterface(const MessageInterface& rhs) noexcept = default;
        MessageInterface& operator=(const MessageInterface& rhs) noexcept = default;
        MessageInterface(MessageInterface&& rhs) noexcept = default;
        MessageInterface& operator=(MessageInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
        CORE_TOOLS_RTTI_DECLARE;

        NODISCARD bool IsExactly(const Rtti& type) const noexcept;
        NODISCARD bool IsDerived(const Rtti& type) const noexcept;
        NODISCARD bool IsExactlyTypeOf(const ConstMessageInterfaceSharedPtr& message) const noexcept;
        NODISCARD bool IsDerivedTypeOf(const ConstMessageInterfaceSharedPtr& message) const noexcept;

        NODISCARD static MessageInterfaceSharedPtr Factory(MessageSource& source, int64_t messageID);

        NODISCARD virtual int GetStreamingSize() const;
        virtual void Save(MessageTarget& target) const;
        virtual void Load(MessageSource& source);

        NODISCARD virtual int32_t GetMessageID() const;
        NODISCARD virtual int32_t GetSubMessageID() const;
        NODISCARD int64_t GetFullMessageID() const noexcept;

        // int32_t �ܳ���
        // int32_t �汾��
        // int64_t ʱ���
        NODISCARD static constexpr int GetMessageHeadSize()
        {
            return sizeof(int32_t) + sizeof(int32_t) + sizeof(int64_t);
        }

    protected:
        // ����ϵͳ��ʹ�õĹ��캯����
        enum class LoadConstructor
        {
            ConstructorLoader
        };

        MessageInterface(MAYBE_UNUSED LoadConstructor value, int64_t messageID) noexcept;

    private:
        int64_t m_MessageID;
    };

    using MessageInterfaceSharedPtr = MessageInterface::MessageInterfaceSharedPtr;
    using ConstMessageInterfaceSharedPtr = MessageInterface::ConstMessageInterfaceSharedPtr;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
