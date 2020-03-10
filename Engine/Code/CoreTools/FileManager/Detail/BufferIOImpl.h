// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 13:38)

#ifndef CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

// 支持读取或写入二进制缓冲区。这个类不支持读写访问。
// 对于BufferIO一个常见的用途是使用FileHandleHelp::LoadFromFile读取整个文件，然后使用BufferIO读取字段。
// 同样，BufferIO可用于将字段写入一个缓冲区，然后使用FileHandleHelper::SaveIntoFile保存整个文件。

// 所有的数据文件都存储为little endian格式，因为大多数平台都是little endian。

// BufferIO类被设计为将整个文件加载到缓冲区，然后解析缓冲区。

#include "CoreTools/FileManager/Flags/BufferIOFlags.h"

#include <boost/noncopyable.hpp> 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BufferIOImpl : private boost::noncopyable
	{
	public:
		using ClassType = BufferIOImpl;

	public:
		// 调用者提供缓冲区的内存，以及是否读取或写入，并负责管理内存。缓冲器不必进行动态分配。
		BufferIOImpl(int bytesTotal, BufferIO type);
		virtual ~BufferIOImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const char* GetBuffer() const = 0;

		int GetBytesTotal() const noexcept;
		int GetBytesProcessed() const noexcept;

		void IncrementBytesProcessed(int bytesNumber) noexcept;

	protected:
		BufferIO GetBufferIOType() const noexcept;
		void SetBytesProcessed(int bytesProcessed) noexcept;

	private:
		int m_BytesTotal;
		int m_BytesProcessed;
		BufferIO m_BufferIOType;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
