///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:28)

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

        // WithNumber����д������ǰд�������������
        // ����д��������������ʽ��WithNumber��WithoutNumber��
        // WithNumber����дelementsNumber����������
        // WithoutNumber��ʾ��дelementsNumber����������

        // д��boolֵΪ4�ֽڡ�
        void WriteBool(bool datum);
        void WriteBoolWithNumber(int32_t elementsNumber, const bool* data);
        void WriteBoolWithoutNumber(int32_t elementsNumber, const bool* data);

        // д���ַ��������ַ���֮ǰд��4���ֽڴ����ȡ�û�п���ֹ����
        void WriteString(const std::string& datum);
        void WriteStringWithNumber(int32_t elementsNumber, const std::string* data);
        void WriteStringWithoutNumber(int32_t elementsNumber, const std::string* data);

        // ԭ������д�뺯����
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

        // д��ö��ֵΪʵ�ʳ��ȡ�
        template <typename T>
        void WriteEnum(T datum);
        template <typename T>
        void WriteEnumWithNumber(int32_t elementsNumber, const T* data);
        template <typename T>
        void WriteEnumWithoutNumber(int32_t elementsNumber, const T* data);

        // ��������
        NODISCARD int GetBytesWritten() const noexcept;

    private:
        MessageBuffer& target;
        ParserStrategy parserStrategy;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
