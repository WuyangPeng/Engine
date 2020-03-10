// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

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
	// дobjects��Ӳ���ļ����汾���ַ����ڶ������֮ǰ��������д�롣
	// ������ʧ��ʱ���׳�Error�쳣��

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
		// ������ͼд�뵽�������С�
		BufferOutStream m_BufferOutStream;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
