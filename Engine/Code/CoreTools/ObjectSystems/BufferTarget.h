// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:38)

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

		// WithNumber会在写入数组前写入数组的数量。函数写入数组有两种形式：WithNumber和WithoutNumber。
		// WithNumber表明写elementsNumber到缓冲区。WithoutNumber表示不写elementsNumber到缓冲区。		

		// 写入bool值为4字节。
		void WriteBool(const bool datum);
		void WriteBoolWithNumber(int elementsNumber, const bool* data);
		void WriteBoolWithoutNumber(int elementsNumber, const bool* data);

		// 写入字符串，在字符串之前写入4个字节代表长度。没有空终止符。
		void WriteString(const std::string& datum);
		void WriteStringWithNumber(int elementsNumber, const std::string* data);
		void WriteStringWithoutNumber(int elementsNumber, const std::string* data);

		// 原生数据写入函数。
		template <typename T>
		void Write(T datum);
		template <typename T>
		void WriteWithNumber(int elementsNumber, const T* data);
		template <typename T>
		void WriteWithoutNumber(int elementsNumber, const T* data);

		template <typename T>
		void Write(const std::vector<T>& datum);

		// 写入枚举值。
		template <typename T>
		void WriteEnum(const T datum);
		template <typename T>
		void WriteEnumWithNumber(int elementsNumber, const T* data);
		template <typename T>
		void WriteEnumWithoutNumber(int elementsNumber, const T* data);

		// 这些模板函数是集合类型。该函数必须被特化，因为它没有提供一个默认的实现。
		template <typename T>
		void WriteAggregate(const T& datum);
		template <typename T>
		void WriteAggregateWithNumber(int elementsNumber, const T* data);
		template <typename T>
		void WriteAggregateWithoutNumber(int elementsNumber, const T* data);

		template <typename T>
		void WriteAggregate(const std::vector<T>& datum);

		// 写入对象指针（uniqueID在磁盘上为[无效]内存指针）。	
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

		// 帮助函数
		int GetBytesWritten() const noexcept;
		void WriteUniqueID(const ConstObjectInterfaceSmartPointer& object);

	private:
		WriteBufferIO m_Target;
		ObjectRegister& m_ObjectRegister;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_H
