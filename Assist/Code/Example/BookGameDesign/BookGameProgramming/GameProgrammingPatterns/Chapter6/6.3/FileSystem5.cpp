// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/27 22:11)

#include "FileSystem5.h"  

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{		 
		FileSystem5& FileSystem5::instance()
		{
			return instance_;
		}

		FileSystem5::FileSystem5()
		{

		}

		FileSystem5 FileSystem5::instance_;
	}
}


