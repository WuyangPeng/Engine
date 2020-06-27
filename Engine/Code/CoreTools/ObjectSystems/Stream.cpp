// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:55)

#include "CoreTools/CoreToolsExport.h"

#include "Stream.h"
#include "StreamSize.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

int CoreTools::Stream
	::GetStreamingSize(const string& input)
{
	// ���ַ�����д�뵽���̣������ǳ��ȣ��������ַ��� 
	// ��û�а�����ֹ���ַ����������Ϊ�ĸ��ֽڵı�����

	auto length = boost::numeric_cast<int>(input.length());
	int padding{ 0 };
	if (0 < length)
	{
		padding = (length % g_DefaultSize);
		if (0 < padding)
		{
			padding = g_DefaultSize - padding;
		}
	}
	return boost::numeric_cast<int>(sizeof(int) + length * sizeof(char) + padding);
}



