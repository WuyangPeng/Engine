// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:55)

#include "CoreTools/CoreToolsExport.h"

#include "Stream.h"
#include "StreamSize.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

int CoreTools::Stream
	::GetStreamingSize(const string& input)
{
	// 该字符串被写入到磁盘，首先是长度，接着是字符， 
	// 但没有包括终止空字符。它被填充为四个字节的倍数。

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



