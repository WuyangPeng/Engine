///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:28)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_H

#include "Network/NetworkDll.h"

#include "MessageBuffer.h"
#include "NetworkMessageInternalFwd.h"

#include <string>
#include <vector>

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageTarget final
    {
    public:
        using ClassType = MessageTarget;
        using ClassShareType = CoreTools::NonCopyClasses;

    public:
        explicit MessageTarget(MessageBuffer& messageBuffer) noexcept;
        ~MessageTarget() noexcept = default;
        MessageTarget(const MessageTarget& rhs) = delete;
        MessageTarget& operator=(const MessageTarget& rhs) = delete;
        MessageTarget(MessageTarget&& rhs) noexcept;
        MessageTarget& operator=(MessageTarget&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        // WithNumber会在写入数组前写入数组的数量。
        // 函数写入数组有两种形式：WithNumber和WithoutNumber。
        // WithNumber表明写elementsNumber到缓冲区。
        // WithoutNumber表示不写elementsNumber到缓冲区。

        // 写入bool值为4字节。
        void WriteBool(bool datum);
        void WriteBoolWithNumber(int32_t elementsNumber, const bool* data);
        void WriteBoolWithoutNumber(int32_t elementsNumber, const bool* data);

        // 写入字符串，在字符串之前写入4个字节代表长度。没有空终止符。
        void WriteString(const std::string& datum);
        void WriteStringWithNumber(int32_t elementsNumber, const std::string* data);
        void WriteStringWithoutNumber(int32_t elementsNumber, const std::string* data);

        // 原生数据写入函数。
        template <typename T>
        void Write(T datum);
        template <typename T>
        void WriteWithNumber(int32_t elementsNumber, const T* data);
        template <typename T>
        void WriteWithoutNumber(int32_t elementsNumber, const T* data);

        template <typename T>
        void Write(const std::vector<T>& datum);

        void Write(const std::string& datum);
        void Write(const std::vector<std::string>& datum);

        // 写入枚举值为实际长度。
        template <typename T>
        void WriteEnum(T datum);
        template <typename T>
        void WriteEnumWithNumber(int32_t elementsNumber, const T* data);
        template <typename T>
        void WriteEnumWithoutNumber(int32_t elementsNumber, const T* data);

        // 帮助函数
        NODISCARD int GetBytesWritten() const noexcept;

    private:
        MessageBuffer& target;
        ParserStrategy parserStrategy;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
