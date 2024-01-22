/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:16)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H

#include "Network/NetworkDll.h"

#include "MessageBuffer.h"
#include "NetworkMessageInternalFwd.h"

#include <string>
#include <vector>

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageSource final
    {
    public:
        using ClassType = MessageSource;
        using ClassShareType = CoreTools::NonCopyClasses;

    public:
        explicit MessageSource(MessageBuffer& messageBuffer) noexcept;

        ~MessageSource() noexcept = default;
        MessageSource(const MessageSource& rhs) = delete;
        MessageSource& operator=(const MessageSource& rhs) = delete;
        MessageSource(MessageSource&& rhs) noexcept;
        MessageSource& operator=(MessageSource&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ��ȡboolֵΪ4�ֽ�
        NODISCARD bool ReadBool();
        void ReadBool(int elementsNumber, bool* data);

        // ��ȡ�ַ��������ַ���֮ǰ��ȡ4���ֽڴ����ȡ�û�п���ֹ����
        NODISCARD std::string ReadString();
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
        NODISCARD int GetBytesRead() const noexcept;
        NODISCARD int GetBytesTotal() const noexcept;
        void IncrementBytesProcessed(int bytesNumber);

    private:
        MessageBuffer& source;
        ParserStrategy parserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_H
