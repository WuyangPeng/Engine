/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:10)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/FileManager/ReadBufferIO.h"

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

        /// 该函数必须被特化，因为它没有提供一个默认的实现。
        template <typename T>
        void ReadAggregate(T& datum);

        template <typename T>
        void ReadAggregateContainer(int elementsNumber, T& container);

        template <typename T>
        void ReadAggregateContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        void ReadAggregateContainer(T& container);

        template <typename T, int Size>
        requires(0 <= Size)
        void ReadAggregateContainer(std::array<T, Size>& container);

        template <typename T>
        NODISCARD T ReadAggregate();

        template <typename T>
        NODISCARD T ReadAggregateContainerUseNumber(int elementsNumber);

        template <typename T>
        NODISCARD T ReadAggregateContainerNotUseNumber();

        template <typename T, int Size>
        requires(0 <= Size)
        NODISCARD std::array<T, Size> ReadAggregateContainer();

        /// 读取对象指针（uniqueId在磁盘上为[无效]内存指针）。
        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
        NODISCARD T ReadObjectAssociated();

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        NODISCARD T ReadObjectAssociatedContainerUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        NODISCARD T ReadObjectAssociatedContainerNotUseNumber();

        template <typename T, int Size>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType> && 0 <= Size)
        NODISCARD std::array<T, Size> ReadObjectAssociatedContainer();

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
        void ReadObjectAssociated(T& datum);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        void ReadObjectAssociatedContainer(int elementsNumber, T& container);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        void ReadObjectAssociatedContainer(T& container);

        template <typename T, int Size>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType> && 0 <= Size)
        void ReadObjectAssociatedContainer(std::array<T, Size>& container);

        /// 读取bool值为4字节
        NODISCARD bool ReadBool();

        template <typename T>
        requires(std::is_same_v<typename T::value_type, bool>)
        NODISCARD T ReadBoolContainerUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, bool>)
        NODISCARD T ReadBoolContainerNotUseNumber();

        template <int Size>
        requires(0 <= Size)
        NODISCARD std::array<bool, Size> ReadBoolContainer();

        void Read(bool& value);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, bool>)
        void ReadBoolContainer(int elementsNumber, T& container);

        void ReadBoolContainer(int elementsNumber, std::set<bool>& container);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, bool>)
        void ReadBoolContainer(T& container);

        template <size_t Size>
        void ReadContainer(std::array<bool, Size>& container);

        /// 读取字符串，在字符串之前读取4个字节代表长度。没有空终止符。
        NODISCARD std::string ReadString();

        template <typename T>
        requires(std::is_same_v<typename T::value_type, std::string>)
        NODISCARD T ReadStringContainerUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, std::string>)
        NODISCARD T ReadStringContainerNotUseNumber();

        template <int Size>
        requires(0 <= Size)
        NODISCARD std::array<std::string, Size> ReadStringContainer();

        void Read(std::string& value);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, std::string>)
        void ReadStringContainer(int elementsNumber, T& container);

        void ReadStringContainer(int elementsNumber, std::set<std::string>& container);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, std::string>)
        void ReadStringContainer(T& container);

        template <int Size>
        requires(0 <= Size)
        void ReadContainer(std::array<std::string, Size>& container);

        /// 原生数据读取函数
        template <typename T>
        requires(std::is_arithmetic_v<T>)
        NODISCARD T Read();

        template <typename T>
        requires(std::is_arithmetic_v<typename T::value_type>)
        NODISCARD T ReadContainerUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_arithmetic_v<T>)
        NODISCARD std::vector<T> ReadVectorUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_arithmetic_v<typename T::value_type>)
        NODISCARD T ReadContainerNotUseNumber();

        template <typename T>
        requires(std::is_arithmetic_v<T>)
        NODISCARD std::vector<T> ReadVectorNotUseNumber();

        template <typename T, size_t Size>
        requires(std::is_arithmetic_v<T>)
        NODISCARD std::array<T, Size> ReadContainer();

        template <typename T>
        requires(std::is_arithmetic_v<T>)
        void Read(T& datum);

        template <typename T>
        requires(std::is_arithmetic_v<typename T::value_type>)
        void ReadContainer(int elementsNumber, T& container);

        template <typename T>
        requires(std::is_arithmetic_v<T>)
        void ReadContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        requires(std::is_arithmetic_v<T>)
        void ReadContainer(int elementsNumber, std::vector<T>& container);

        template <typename T>
        requires(std::is_arithmetic_v<typename T::value_type>)
        void ReadContainer(T& container);

        template <typename T, size_t Size>
        requires(std::is_arithmetic_v<T>)
        void ReadContainer(std::array<T, Size>& container);

        /// 读取枚举值为4个字节。
        template <typename T>
        requires(std::is_enum_v<T>)
        NODISCARD T ReadEnum();

        template <typename T>
        requires(std::is_enum_v<typename T::value_type>)
        NODISCARD T ReadEnumContainerUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_enum_v<T>)
        NODISCARD std::vector<T> ReadEnumVectorUseNumber(int elementsNumber);

        template <typename T>
        requires(std::is_enum_v<typename T::value_type>)
        NODISCARD T ReadEnumContainerNotUseNumber();

        template <typename T>
        requires(std::is_enum_v<T>)
        NODISCARD std::vector<T> ReadEnumVectorNotUseNumber();

        template <typename T, int Size>
        requires(std::is_enum_v<T> && 0 <= Size)
        NODISCARD std::array<T, Size> ReadEnumContainer();

        template <typename T>
        requires(std::is_enum_v<T>)
        void ReadEnum(T& datum);

        template <typename T>
        requires(std::is_enum_v<typename T::value_type>)
        void ReadEnumContainer(int elementsNumber, T& container);

        template <typename T>
        requires(std::is_enum_v<T>)
        void ReadEnumContainer(int elementsNumber, std::set<T>& container);

        template <typename T>
        requires(std::is_enum_v<T>)
        void ReadEnumContainer(int elementsNumber, std::vector<T>& container);

        template <typename T>
        requires(std::is_enum_v<typename T::value_type>)
        void ReadEnumContainer(T& container);

        template <typename T, int Size>
        requires(std::is_enum_v<T> && 0 <= Size)
        void ReadEnumContainer(std::array<T, Size>& container);

        /// 帮助函数
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
