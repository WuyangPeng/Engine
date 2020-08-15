// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.4 (2020/03/10 14:31)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H

#include "Network/NetworkDll.h"

#include "MessageBuffer.h"
#include "NetworkMessageInternalFwd.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <vector>

EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageSource : private boost::noncopyable
    {
    public:
        using ClassType = MessageSource;
        using ClassShareType = CoreTools::NonCopyClasses;

    public:
        explicit MessageSource(const MessageBufferSharedPtr& messageBuffer) noexcept;

        ~MessageSource() = default;
        MessageSource(const MessageSource& rhs) = delete;
        MessageSource& operator=(const MessageSource& rhs) = delete;
        MessageSource(MessageSource&& rhs) noexcept;
        MessageSource& operator=(MessageSource&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 读取bool值为4字节
        bool ReadBool();
        void ReadBool(int elementsNumber, bool* data);

        // 读取字符串，在字符串之前读取4个字节代表长度。没有空终止符。
        std::string ReadString();
        void ReadString(int elementsNumber, std::string* data);

        // 原生数据读取函数
        template <typename T>
        void Read(T& datum);
        template <typename T>
        void Read(int elementsNumber, T* data);

        template <typename T>
        void Read(std::vector<T>& datum);

        void Read(std::string& datum);
        void Read(std::vector<std::string>& datum);

        // 读取枚举值为实际长度。
        template <typename T>
        void ReadEnum(T& datum);
        template <typename T>
        void ReadEnum(int elementsNumber, T* data);

        // 帮助函数
        int GetBytesRead() const noexcept;
        int GetBytesTotal() const noexcept;
        void IncrementBytesProcessed(int bytesNumber);

    private:
        MessageBufferSharedPtr m_Source;
        ParserStrategy m_ParserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H
