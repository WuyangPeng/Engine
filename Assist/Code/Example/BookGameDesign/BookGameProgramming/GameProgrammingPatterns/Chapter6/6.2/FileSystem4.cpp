// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/27 22:11)

#include "FileSystem4.h" 
#include "PS3FileSystem.h"
#include "WiiFileSystem.h"

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		FileSystem4& FileSystem4::instance()
		{
#if PLATFORM == PLAYSTATION3
			static FileSystem4* instance = new PS3FileSystem();
#elif PLATFORM == WII
			static FileSystem4* instance = new WiiFileSystem();
#endif
			return *instance;
		}

		FileSystem4::~FileSystem4()
		{

		}

		FileSystem4::FileSystem4()
		{

		}
	}
}


