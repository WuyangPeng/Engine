// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Stream
	{
	public:
		using ClassType = Stream;

	public:
		// ����������ش洢�ַ���������ֽ������ַ�������������Ϊһ���������洢��������������ַ���
		// ���ַ���������䣬ʹ�ܴ洢��ʹ���ĸ��ֽڵı�����
		static int GetStreamingSize(const std::string& input);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
