/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:16)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Helper/StreamMacro.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageInterface
    {
    public:
        using ClassType = MessageInterface;

        CORE_TOOLS_SHARED_PTR_DECLARE(MessageInterface);
        using Rtti = CoreTools::Rtti;
        using FactoryFunction = MessageInterfaceSharedPtr (*)(MessageSource& stream, MessageHeadStrategy messageHeadStrategy, int64_t messageId);

    public:
        MessageInterface(MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept;
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

        NODISCARD static MessageInterfaceSharedPtr Factory(MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageId);

        NODISCARD virtual int GetStreamingSize() const;
        virtual void Save(MessageTarget& target) const;
        virtual void Load(MessageSource& source);

        NODISCARD int GetBaseStreamingSize() const;

        // int32_t 总长度
        // int32_t 版本号
        // int64_t 时间戳
        NODISCARD static consteval int GetMessageHeadSize() noexcept
        {
            return sizeof(int32_t) + sizeof(int32_t) + sizeof(int64_t);
        }

        NODISCARD int32_t GetMessageId() const;
        NODISCARD int32_t GetSubMessageId() const;
        NODISCARD int64_t GetFullMessageId() const noexcept;

        NODISCARD MessageHeadStrategy GetMessageHeadStrategy() const noexcept;

    protected:
        // 加载系统所使用的构造函数。
        enum class LoadConstructor
        {
            ConstructorLoader
        };

        MessageInterface(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept;

    protected:
        NODISCARD bool IsUseProtoBuf() const noexcept;
        NODISCARD bool IsUseJson() const noexcept;

    private:
        static constexpr auto messageBytes = 32LL;
        static constexpr auto maxMessageId = (1LL << messageBytes) - 1LL;

    private:
        MessageHeadStrategy messageHeadStrategy;
        int64_t messageId;
    };

    using MessageInterfaceSharedPtr = MessageInterface::MessageInterfaceSharedPtr;
    using ConstMessageInterfaceSharedPtr = MessageInterface::ConstMessageInterfaceSharedPtr;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
