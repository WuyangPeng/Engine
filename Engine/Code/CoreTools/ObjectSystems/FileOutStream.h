// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferOutStream.h"
#include "ObjectSystemsFwd.h"
#include "System/Helper/UnicodeUsing.h"

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

#include <string>

namespace CoreTools
{
	// 写objects到硬盘文件。版本号字符串在顶层对象之前，被首先写入。
	// 当操作失败时，抛出Error异常。

	class CORE_TOOLS_DEFAULT_DECLARE FileOutStream : private boost::noncopyable
	{
	public:
		using ClassType = FileOutStream;
		using ClassShareType = CoreTools::NonCopyClasses;
		using String = System::String;

	public:
		explicit FileOutStream(const OutTopLevel& topLevel);

		CLASS_INVARIANT_DECLARE;

		void Save(const String& fileName);

	private:
		// 将场景图写入到缓冲器中。
		BufferOutStream m_BufferOutStream;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
