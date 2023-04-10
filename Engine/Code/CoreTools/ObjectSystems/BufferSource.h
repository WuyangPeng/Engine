///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:27)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <array>
#include <set>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferSource final
    {
    public:
        using ClassType = BufferSource;
        using ClassShareType = NonCopyClasses;

    public:
        explicit BufferSource(const ConstFileBufferSharedPtr& fileBuffer);
        ~BufferSource() noexcept = default;
        BufferSource(const BufferSource& rhs) noexcept = delete;
        BufferSource& operator=(const BufferSource& rhs) noexcept = delete;
        BufferSource(BufferSource&& rhs) noexcept = delete;
        BufferSource& operator=(BufferSource&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // �ú������뱻�ػ�����Ϊ��û���ṩһ��Ĭ�ϵ�ʵ�֡�
        template <typename T>
        void ReadAggregate(T& datum);

        template <typename T>
        void ReadAggregateContainer(int elementsNumber, T& container);

        template <typename T>
        void ReadAggregateContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        void ReadAggregateContainer(T& container);

        template <typename T, int Size>
        void ReadAggregateContainer(std::array<T, Size>& container);

        //  ��ȡ����ָ�루uniqueID�ڴ�����Ϊ[��Ч]�ڴ�ָ�룩��
        template <typename T>
        NODISCARD T ReadObjectAssociated();

        template <typename T>
        NODISCARD T ReadObjectAssociatedContainerWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadObjectAssociatedContainerWithoutNumber();

        template <typename T, int Size>
        NODISCARD std::array<T, Size> ReadObjectAssociatedContainer();

        template <typename T>
        void ReadObjectAssociated(T& datum);

        template <typename T>
        void ReadObjectAssociatedContainer(int elementsNumber, T& container);

        template <typename T>
        void ReadObjectAssociatedContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        void ReadObjectAssociatedContainer(T& container);

        template <typename T, int Size>
        void ReadObjectAssociatedContainer(std::array<T, Size>& container);

        // ��ȡboolֵΪ4�ֽ�
        NODISCARD bool ReadBool();

        template <typename T>
        NODISCARD T ReadBoolContainerWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadBoolContainerWithoutNumber();

        template <int Size>
        NODISCARD std::array<bool, Size> ReadBoolContainer();

        void Read(bool& value);

        template <typename T>
        void ReadBoolContainer(int elementsNumber, T& container);

        void ReadBoolContainer(int elementsNumber, std::set<bool>& container);

        template <typename T>
        void ReadBoolContainer(T& container);

        template <int Size>
        void ReadContainer(std::array<bool, Size>& container);

        // ��ȡ�ַ��������ַ���֮ǰ��ȡ4���ֽڴ����ȡ�û�п���ֹ����
        NODISCARD std::string ReadString();

        template <typename T>
        NODISCARD T ReadStringContainerWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadStringContainerWithoutNumber();

        template <int Size>
        NODISCARD std::array<std::string, Size> ReadStringContainer();

        void Read(std::string& value);

        template <typename T>
        void ReadStringContainer(int elementsNumber, T& container);

        void ReadStringContainer(int elementsNumber, std::set<std::string>& container);

        template <typename T>
        void ReadStringContainer(T& container);

        template <int Size>
        void ReadContainer(std::array<std::string, Size>& container);

        // ԭ�����ݶ�ȡ����
        template <typename T>
        NODISCARD T Read();

        template <typename T>
        NODISCARD T ReadContainerWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD std::vector<T> ReadVectorWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadContainerWithoutNumber();

        template <typename T>
        NODISCARD std::vector<T> ReadVectorWithoutNumber();

        template <typename T, int Size>
        NODISCARD std::array<T, Size> ReadContainer();

        template <typename T>
        void Read(T& datum);

        template <typename T>
        void ReadContainer(int elementsNumber, T& container);

        template <typename T>
        void ReadContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        void ReadContainer(int elementsNumber, std::vector<T>& container);

        template <typename T>
        void ReadContainer(T& container);

        template <typename T, int Size>
        void ReadContainer(std::array<T, Size>& container);

        // ��ȡö��ֵΪ4�ֽڡ�
        template <typename T>
        NODISCARD T ReadEnum();

        template <typename T>
        NODISCARD T ReadEnumContainerWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD std::vector<T> ReadEnumVectorWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadEnumContainerWithoutNumber();

        template <typename T>
        NODISCARD std::vector<T> ReadEnumVectorWithoutNumber();

        template <typename T, int Size>
        NODISCARD std::array<T, Size> ReadEnumContainer();

        template <typename T>
        void ReadEnum(T& datum);

        template <typename T>
        void ReadEnumContainer(int elementsNumber, T& container);

        template <typename T>
        void ReadEnumContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        void ReadEnumContainer(int elementsNumber, std::vector<T>& container);

        template <typename T>
        void ReadEnumContainer(T& container);

        template <typename T, int Size>
        void ReadEnumContainer(std::array<T, Size>& container);

        // ��Щģ�庯���Ǽ������͡�

        template <typename T>
        NODISCARD T ReadAggregate();

        template <typename T>
        NODISCARD T ReadAggregateContainerWithNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadAggregateContainerWithoutNumber();

        template <typename T, int Size>
        NODISCARD std::array<T, Size> ReadAggregateContainer();

        // ��������
        NODISCARD int GetBytesRead() const noexcept;
        NODISCARD int GetBytesTotal() const;
        void IncrementBytesProcessed(int bytesNumber);
        void ReadUniqueId(ObjectInterface& object);

    private:
        NODISCARD int32_t GetElementsNumber();

    private:
        ReadBufferIO source;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BufferSource);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
