/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:54)

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

        /// ����д��������������ʽ��WithNumber��WithoutNumber��
        /// ������������ΪelementsNumber��
        /// WithNumber����дelementsNumber����������
        /// WithoutNumber��ʾ��дelementsNumber����������
        /// array������д�������������

        // ��Щģ�庯���Ǽ������͡��ú������뱻�ػ�����Ϊ��û���ṩһ��Ĭ�ϵ�ʵ�֡�
        template <typename T>
        void WriteAggregate(const T& datum);

        template <typename T>
        void WriteAggregateContainerWithNumber(const T& objects);

        template <typename T>
        void WriteAggregateContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        void WriteAggregateContainer(const std::array<T, Size>& objects);

        // д�����ָ�루uniqueID�ڴ�����Ϊ[��Ч]�ڴ�ָ�룩��
        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
        void WriteObjectAssociated(const T& object);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
        void WriteWeakObjectAssociated(const T& object);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        void WriteObjectAssociatedContainerWithNumber(const T& objects);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        void WriteObjectAssociatedContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType> && 0 <= Size)
        void WriteObjectAssociatedContainer(const std::array<T, Size>& objects);

        // д��boolֵΪ4�ֽڡ�
        void Write(bool datum);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, bool>)
        void WriteBoolContainerWithNumber(const T& objects);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, bool>)
        void WriteBoolContainerWithoutNumber(const T& objects);

        template <int Size>
        requires(0 <= Size)
        void WriteContainer(const std::array<bool, Size>& objects);

        // д���ַ��������ַ���֮ǰд��4���ֽڴ����ȡ�û�п���ֹ����
        void Write(const char* datum);
        void Write(const std::string& datum);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, std::string> || std::is_same_v<typename T::value_type, const char*>)
        void WriteStringContainerWithNumber(const T& objects);

        template <typename T>
        requires(std::is_same_v<typename T::value_type, std::string> || std::is_same_v<typename T::value_type, const char*>)
        void WriteStringContainerWithoutNumber(const T& objects);

        template <int Size>
        requires(0 <= Size)
        void WriteContainer(const std::array<std::string, Size>& objects);

        template <int Size>
        requires(0 <= Size)
        void WriteContainer(const std::array<const char*, Size>& objects);

        // ԭ������д�뺯����
        template <typename T>
        requires(std::is_arithmetic_v<T>)
        void Write(T datum);

        template <typename T>
        requires(std::is_arithmetic_v<typename T::value_type>)
        void WriteContainerWithNumber(const T& objects);

        template <typename T>
        requires(std::is_arithmetic_v<typename T::value_type>)
        void WriteContainerWithoutNumber(const T& objects);

        template <typename T, size_t Size>
        requires(std::is_arithmetic_v<T>)
        void WriteContainer(const std::array<T, Size>& objects);

        // д��ö��ֵ��
        template <typename T>
        requires(std::is_enum_v<T>)
        void WriteEnum(T datum);

        template <typename T>
        requires(std::is_enum_v<typename T::value_type>)
        void WriteEnumContainerWithNumber(const T& objects);

        template <typename T>
        requires(std::is_enum_v<typename T::value_type>)
        void WriteEnumContainerWithoutNumber(const T& objects);

        template <typename T, int Size>
        requires(std::is_enum_v<T> && 0 <= Size)
        void WriteEnumContainer(const std::array<T, Size>& objects);

        // ��������
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
