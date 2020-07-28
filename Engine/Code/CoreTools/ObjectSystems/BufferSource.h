// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:38)

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

		// 读取bool值为4字节
		bool ReadBool();
		void ReadBool(int elementsNumber, bool* data);

		// 读取字符串，在字符串之前读取4个字节代表长度。没有空终止符。
		std::string ReadString();
		void ReadString(int elementsNumber, std::string* data);

		// 原生数据读取函数
		template <typename T>
		void Read(T& datum);
		template <typename T>
		void Read(int elementsNumber, T* data);

		template <typename T>
		void Read(std::vector<T>& datum);

		// 读取枚举值为4字节。
		template <typename T>
		void ReadEnum(T& datum);
		template <typename T>
		void ReadEnum(int elementsNumber, T* data);

		//  读取对象指针（uniqueID在磁盘上为[无效]内存指针）。
		template <typename T>
		void ReadSmartPointer(T& object);
		template <typename T>
		void ReadSmartPointer(int elementsNumber, T* objects);

		template <typename T>
		void ReadSmartPointer(std::vector<T>& datum);

		// 这些模板函数是集合类型。
		// 该函数必须被特化，因为它没有提供一个默认的实现。
		template <typename T>
		void ReadAggregate(T& datum);
		template <typename T>
		void ReadAggregate(int elementsNumber, T* data);

		template <typename T>
		void ReadAggregate(std::vector<T>& datum);

		// 帮助函数
		int GetBytesRead() const noexcept;
		int GetBytesTotal() const noexcept;
		void IncrementBytesProcessed(int bytesNumber) noexcept;
		void ReadUniqueID(ObjectInterfaceSmartPointer& object);

	private:
		ReadBufferIO m_Source;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_H
