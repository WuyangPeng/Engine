/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:54)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <array>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(BufferTargetImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferTarget final
    {
    public:
        NON_COPY_TYPE_DECLARE(BufferTarget);

    public:
        BufferTarget(int bufferSize, const ConstObjectRegisterSharedPtr& objectRegister);

        CLASS_INVARIANT_DECLARE;

        /// 函数写入数组有两种形式：WithNumber和WithoutNumber。
        /// 假设数组数量为elementsNumber，
        /// WithNumber表明写elementsNumber到缓冲区，
        /// WithoutNumber表示不写elementsNumber到缓冲区。
        /// array容器不写入数组的数量。

        // 这些模板函数是集合类型。该函数必须被特化，因为它没有提供一个默认的实现。
        template <typename T>
        void WriteAggregate(const T& datum);

        template <typename T>
        void WriteAggregateContainerWithNumber(const T& objects);

        template <typename T>
        void WriteAggregateContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        void WriteAggregateContainer(const std::array<T, Size>& objects);

        // 写入对象指针（uniqueID在磁盘上为[无效]内存指针）。
        template <typename T>
        void WriteObjectAssociated(const T& object);

        template <typename T>
        void WriteWeakObjectAssociated(const T& object);

        template <typename T>
        void WriteObjectAssociatedContainerWithNumber(const T& objects);

        template <typename T>
        void WriteObjectAssociatedContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        void WriteObjectAssociatedContainer(const std::array<T, Size>& objects);

        // 写入bool值为4字节。
        void Write(bool datum);

        template <typename T>
        void WriteBoolContainerWithNumber(const T& objects);

        template <typename T>
        void WriteBoolContainerWithoutNumber(const T& objects);

        template <int Size>
        void WriteContainer(const std::array<bool, Size>& objects);

        // 写入字符串，在字符串之前写入4个字节代表长度。没有空终止符。
        void Write(const char* datum);
        void Write(const std::string& datum);

        template <typename T>
        void WriteStringContainerWithNumber(const T& objects);

        template <typename T>
        void WriteStringContainerWithoutNumber(const T& objects);

        template <int Size>
        void WriteContainer(const std::array<std::string, Size>& objects);

        template <int Size>
        void WriteContainer(const std::array<const char*, Size>& objects);

        // 原生数据写入函数。
        template <typename T>
        void Write(T datum);

        template <typename T>
        void WriteContainerWithNumber(const T& objects);

        template <typename T>
        void WriteContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        void WriteContainer(const std::array<T, Size>& objects);

        // 写入枚举值。
        template <typename T>
        void WriteEnum(T datum);

        template <typename T>
        void WriteEnumContainerWithNumber(const T& objects);

        template <typename T>
        void WriteEnumContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        void WriteEnumContainer(const std::array<T, Size>& objects);

        // 帮助函数
        NODISCARD int GetBytesWritten() const noexcept;
        void WriteUniqueId(const ConstObjectInterfaceSharedPtr& object);

        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const noexcept;

    private:
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BufferTarget);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
