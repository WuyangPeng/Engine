// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	// �Ӵ����ļ��ж�ȡ���󡣰汾�ַ������ȱ���ȡ���������version��Ƚϣ�
	// ��������ַ����������ô�������󱻶�ȡ��	
	class CORE_TOOLS_DEFAULT_DECLARE FileInStream
	{
	public:
		using ClassType = FileInStream;
		using String = System::String;

	public:
		explicit FileInStream(const String& fileName);
 

		CLASS_INVARIANT_DECLARE;

		InTopLevel GetInTopLevel() const noexcept;

	private:
		void Load(const String& fileName);

	private:
		InTopLevel m_InTopLevel;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H
