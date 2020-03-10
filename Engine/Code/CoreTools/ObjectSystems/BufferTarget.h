// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectSystemsFwd.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <vector>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BufferTarget : private boost::noncopyable
	{
	public:
		using ClassType = BufferTarget;
		using FileBufferPtr = std::shared_ptr<FileBuffer>;
		using ClassShareType = CoreTools::NonCopyClasses;

	public:
		BufferTarget(const FileBufferPtr& fileBufferPtr, ObjectRegister& objectRegister);
		~BufferTarget();

		CLASS_INVARIANT_DECLARE;

		// WithNumber����д������ǰд�����������������д��������������ʽ��WithNumber��WithoutNumber��
		// WithNumber����дelementsNumber����������WithoutNumber��ʾ��дelementsNumber����������		

		// д��boolֵΪ4�ֽڡ�
		void WriteBool(const bool datum);
		void WriteBoolWithNumber(int elementsNumber, const bool* data);
		void WriteBoolWithoutNumber(int elementsNumber, const bool* data);

		// д���ַ��������ַ���֮ǰд��4���ֽڴ����ȡ�û�п���ֹ����
		void WriteString(const std::string& datum);
		void WriteStringWithNumber(int elementsNumber, const std::string* data);
		void WriteStringWithoutNumber(int elementsNumber, const std::string* data);

		// ԭ������д�뺯����
		template <typename T>
		void Write(T datum);
		template <typename T>
		void WriteWithNumber(int elementsNumber, const T* data);
		template <typename T>
		void WriteWithoutNumber(int elementsNumber, const T* data);

		template <typename T>
		void Write(const std::vector<T>& datum);

		// д��ö��ֵ��
		template <typename T>
		void WriteEnum(const T datum);
		template <typename T>
		void WriteEnumWithNumber(int elementsNumber, const T* data);
		template <typename T>
		void WriteEnumWithoutNumber(int elementsNumber, const T* data);

		// ��Щģ�庯���Ǽ������͡��ú������뱻�ػ�����Ϊ��û���ṩһ��Ĭ�ϵ�ʵ�֡�
		template <typename T>
		void WriteAggregate(const T& datum);
		template <typename T>
		void WriteAggregateWithNumber(int elementsNumber, const T* data);
		template <typename T>
		void WriteAggregateWithoutNumber(int elementsNumber, const T* data);

		template <typename T>
		void WriteAggregate(const std::vector<T>& datum);

		// д�����ָ�루uniqueID�ڴ�����Ϊ[��Ч]�ڴ�ָ�룩��	
		template <typename T>
		void WritePointer(const T* object);
		template <typename T>
		void WritePointerWithNumber(int elementsNumber, T* const* objects);
		template <typename T>
		void WritePointerWithoutNumber(int elementsNumber, T* const* objects);

		template <typename T>
		void WriteSmartPointer(const T& object);
		template <typename T>
		void WriteSmartPointerWithNumber(int elementsNumber, const T* objects);
		template <typename T>
		void WriteSmartPointerWithoutNumber(int elementsNumber, const T* objects);

		template <typename T>
		void WriteSmartPointer(const std::vector<T>& datum);

		// ��������
		int GetBytesWritten() const noexcept;
		void WriteUniqueID(const ConstObjectInterfaceSmartPointer& object);

	private:
		WriteBufferIO m_Target;
		ObjectRegister& m_ObjectRegister;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
