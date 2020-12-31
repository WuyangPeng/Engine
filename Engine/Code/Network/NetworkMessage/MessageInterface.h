//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:01)

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
        using FactoryFunction = MessageInterfaceSharedPtr (*)(const MessageSourceSharedPtr& stream, int64_t messageID);

    public:
        explicit MessageInterface(int64_t messageID) noexcept;
        virtual ~MessageInterface() noexcept = 0;
        MessageInterface(const MessageInterface& rhs) = default;
        MessageInterface& operator=(const MessageInterface& rhs) = default;
        MessageInterface(MessageInterface&& rhs) noexcept = default;
        MessageInterface& operator=(MessageInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
        CORE_TOOLS_RTTI_DECLARE;

        [[nodiscard]] bool IsExactly(const Rtti& type) const noexcept;
        [[nodiscard]] bool IsDerived(const Rtti& type) const noexcept;
        [[nodiscard]] bool IsExactlyTypeOf(const ConstMessageInterfaceSharedPtr& message) const noexcept;
        [[nodiscard]] bool IsDerivedTypeOf(const ConstMessageInterfaceSharedPtr& message) const noexcept;

        [[nodiscard]] static MessageInterfaceSharedPtr Factory(const MessageSourceSharedPtr& source, int64_t messageID);

        [[nodiscard]] virtual int GetStreamingSize() const;
        virtual void Save(const MessageTargetSharedPtr& target) const;
        virtual void Load(const MessageSourceSharedPtr& source);

        [[nodiscard]] virtual int GetMessageID() const;
        [[nodiscard]] virtual int GetSubMessageID() const;
        [[nodiscard]] int64_t GetFullMessageID() const noexcept;

        // int32_t 总长度
        // int32_t 版本号
        // int64_t 时间戳
        [[nodiscard]] static constexpr int GetMessageHeadSize()
        {
            return sizeof(int32_t) + sizeof(int32_t) + sizeof(int64_t);
        }

    protected:
        // 加载系统所使用的构造函数。
        enum class LoadConstructor
        {
            ConstructorLoader
        };

        MessageInterface(LoadConstructor value, int64_t messageID) noexcept;

    private:
        int64_t m_MessageID;
    };

    using MessageInterfaceSharedPtr = MessageInterface::MessageInterfaceSharedPtr;
    using ConstMessageInterfaceSharedPtr = MessageInterface::ConstMessageInterfaceSharedPtr;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
