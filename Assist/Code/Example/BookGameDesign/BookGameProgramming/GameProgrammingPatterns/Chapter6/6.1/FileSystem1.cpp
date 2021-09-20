// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/26 21:41)

#include "FileSystem1.h" 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{		
		FileSystem1& FileSystem1::instance()
		{
			// lazy initialize.
			if (instance_ == nullptr)
			{
				instance_ = new FileSystem1();
			}
			return *instance_;
		}

		FileSystem1::FileSystem1()
		{

		}

		FileSystem1* FileSystem1::instance_;
	}
}


