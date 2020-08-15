// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.4 (2020/03/10 14:31)

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

        // ��ȡboolֵΪ4�ֽ�
        bool ReadBool();
        void ReadBool(int elementsNumber, bool* data);

        // ��ȡ�ַ��������ַ���֮ǰ��ȡ4���ֽڴ����ȡ�û�п���ֹ����
        std::string ReadString();
        void ReadString(int elementsNumber, std::string* data);

        // ԭ�����ݶ�ȡ����
        template <typename T>
        void Read(T& datum);
        template <typename T>
        void Read(int elementsNumber, T* data);

        template <typename T>
        void Read(std::vector<T>& datum);

        void Read(std::string& datum);
        void Read(std::vector<std::string>& datum);

        // ��ȡö��ֵΪʵ�ʳ��ȡ�
        template <typename T>
        void ReadEnum(T& datum);
        template <typename T>
        void ReadEnum(int elementsNumber, T* data);

        // ��������
        int GetBytesRead() const noexcept;
        int GetBytesTotal() const noexcept;
        void IncrementBytesProcessed(int bytesNumber);

    private:
        MessageBufferSharedPtr m_Source;
        ParserStrategy m_ParserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H
