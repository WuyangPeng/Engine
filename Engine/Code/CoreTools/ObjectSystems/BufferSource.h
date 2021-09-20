//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/21 14:19)

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
        using ClassShareType = CoreTools::NonCopyClasses;

    public:
        explicit BufferSource(const ConstFileBufferSharedPtr& fileBuffer);
        ~BufferSource() noexcept = default;
        BufferSource(const BufferSource& rhs) noexcept = delete;
        BufferSource& operator=(const BufferSource& rhs) noexcept = delete;
        BufferSource(BufferSource&& rhs) noexcept = delete;
        BufferSource& operator=(BufferSource&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // 读取bool值为4字节
        [[nodiscard]] bool ReadBool();

        template <typename T>
        [[nodiscard]] T ReadBoolContainerWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] T ReadBoolContainerWithoutNumber();

        template <int Size>
        [[nodiscard]] std::array<bool, Size> ReadBoolContainer();

        void Read(bool& value);

        template <typename T>
        void ReadBoolContainer(int elementsNumber, T& container);

        void ReadBoolContainer(int elementsNumber, std::set<bool>& container);

        template <typename T>
        void ReadBoolContainer(T& container);

        template <int Size>
        void ReadContainer(std::array<bool, Size>& container);

        // 读取字符串，在字符串之前读取4个字节代表长度。没有空终止符。
        [[nodiscard]] std::string ReadString();

        template <typename T>
        [[nodiscard]] T ReadStringContainerWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] T ReadStringContainerWithoutNumber();

        template <int Size>
        [[nodiscard]] std::array<std::string, Size> ReadStringContainer();

        void Read(std::string& value);

        template <typename T>
        void ReadStringContainer(int elementsNumber, T& container);

        void ReadStringContainer(int elementsNumber, std::set<std::string>& container);

        template <typename T>
        void ReadStringContainer(T& container);

        template <int Size>
        void ReadContainer(std::array<std::string, Size>& container);

        // 原生数据读取函数
        template <typename T>
        [[nodiscard]] T Read();

        template <typename T>
        [[nodiscard]] T ReadContainerWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] std::vector<T> ReadVectorWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] T ReadContainerWithoutNumber();

        template <typename T>
        [[nodiscard]] std::vector<T> ReadVectorWithoutNumber();

        template <typename T, int Size>
        [[nodiscard]] std::array<T, Size> ReadContainer();

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

        // 读取枚举值为4字节。
        template <typename T>
        [[nodiscard]] T ReadEnum();

        template <typename T>
        [[nodiscard]] T ReadEnumContainerWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] std::vector<T> ReadEnumVectorWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] T ReadEnumContainerWithoutNumber();

        template <typename T>
        [[nodiscard]] std::vector<T> ReadEnumVectorWithoutNumber();

        template <typename T, int Size>
        [[nodiscard]] std::array<T, Size> ReadEnumContainer();

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

        // 这些模板函数是集合类型。

        template <typename T>
        [[nodiscard]] T ReadAggregate();

        template <typename T>
        [[nodiscard]] T ReadAggregateContainerWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] T ReadAggregateContainerWithoutNumber();

        template <typename T, int Size>
        [[nodiscard]] std::array<T, Size> ReadAggregateContainer();

        // 该函数必须被特化，因为它没有提供一个默认的实现。
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

        //  读取对象指针（uniqueID在磁盘上为[无效]内存指针）。
        template <typename T>
        [[nodiscard]] T ReadObjectAssociated();

        template <typename T>
        [[nodiscard]] T ReadObjectAssociatedContainerWithNumber(int elementsNumber);

        template <typename T>
        [[nodiscard]] T ReadObjectAssociatedContainerWithoutNumber();

        template <typename T, int Size>
        [[nodiscard]] std::array<T, Size> ReadObjectAssociatedContainer();

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

        // 帮助函数
        int GetBytesRead() const noexcept;
        int GetBytesTotal() const;
        void IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        void ReadUniqueID(const ObjectInterfaceSharedPtr& object);

    private:
        int32_t GetElementsNumber();

    private:
        ReadBufferIO m_Source;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BufferSource);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
