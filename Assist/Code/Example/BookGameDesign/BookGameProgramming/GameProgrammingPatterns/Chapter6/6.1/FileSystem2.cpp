// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/26 21:41)

#include "FileSystem2.h" 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{		
		FileSystem2& FileSystem2::instance()
		{
			static FileSystem2* instance = new FileSystem2();
		 
			return *instance;
		}

		FileSystem2::FileSystem2()
		{

		}
	}
}


