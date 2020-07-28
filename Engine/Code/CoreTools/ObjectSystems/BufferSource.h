// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

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
		explicit BufferSource(const FileBufferPtr& fileBufferPtr);
 

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
		int GetBytesTotal() const noexcept;
		void IncrementBytesProcessed(int bytesNumber) noexcept;
		void ReadUniqueID(ObjectInterfaceSmartPointer& object);

	private:
		ReadBufferIO m_Source;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
