// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "WeakPtr.h"
#include <array>
#include <vector>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferSource : private boost::noncopyable
    {
    public:
        using ClassType = BufferSource;
        using FileBufferPtr = std::shared_ptr<FileBuffer>;
        using ClassShareType = CoreTools::NonCopyClasses;

    public:
        explicit BufferSource(const ConstFileBufferSharedPtr& fileBuffer);

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

        template <typename T, int Size>
        void Read(std::array<T, Size>& datum);

        // ��ȡö��ֵΪ4�ֽڡ�
        template <typename T>
        void ReadEnum(T& datum);
        template <typename T>
        void ReadEnum(int elementsNumber, T* data);

        //  ��ȡ����ָ�루uniqueID�ڴ�����Ϊ[��Ч]�ڴ�ָ�룩��
        template <typename T>
        void ReadSmartPointer(T& object);
        template <typename T>
        void ReadSmartPointer(int elementsNumber, T* objects);

        template <typename T>
        void ReadSmartPointer(std::vector<T>& datum);

        template <typename T>
        void ReadWeakPtr(WeakPtr<T>& object);
        template <typename T>
        void ReadWeakPtr(std::vector<WeakPtr<T>>& datum);
        template <typename T, int size>
        void ReadWeakPtr(std::array<WeakPtr<T>, size>& datum);

        // ��Щģ�庯���Ǽ������͡�
        // �ú������뱻�ػ�����Ϊ��û���ṩһ��Ĭ�ϵ�ʵ�֡�
        template <typename T>
        void ReadAggregate(T& datum);
        template <typename T>
        void ReadAggregate(int elementsNumber, T* data);

        template <typename T>
        void ReadAggregate(std::vector<T>& datum);

        // ��������
        int GetBytesRead() const noexcept;
        int GetBytesTotal() const  ;
        void IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        void ReadUniqueID(ObjectInterfaceSharedPtr object);

    private:
        ReadBufferIO m_Source;
    };

     using BufferSourceSharedPtr = std::shared_ptr<BufferSource>;
    using ConstBufferSourceSharedPtr = std::shared_ptr<const BufferSource>;

}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
