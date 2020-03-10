// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:31)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace CoreTools
{
	// 写objects到内存块。当操作失败时，抛出Error异常。
	class CORE_TOOLS_HIDDEN_DECLARE BufferOutStreamImpl : private boost::noncopyable
	{
	public:
		using ClassType = BufferOutStreamImpl;
		using FileBufferPtr = std::shared_ptr<FileBuffer>;

	public:
		explicit BufferOutStreamImpl(const OutTopLevel& topLevel);

		CLASS_INVARIANT_DECLARE;

		FileBufferPtr GetBufferOutStreamInformation() const;

	private:
		using BufferTargetPtr = std::shared_ptr<BufferTarget>;

	private:
		void GenerateBuffer();
		void Register();
		int GetBufferSize();
		void ResetBufferSize(int bufferSize);
		void SaveToBuffer();

	private:
		// 顶层对象的流。
		OutTopLevel m_TopLevel;

		// 存储objects，对顶层对象使用图的深度优先遍历。
		ObjectRegister m_ObjectRegister;

		FileBufferPtr m_BufferPtr;
		BufferTargetPtr m_TargetPtr;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
