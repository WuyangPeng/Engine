// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/27 22:09)

#ifndef BOOK_GAME_PROGRAMMING_WII_FILE_SYSTEM_H 
#define BOOK_GAME_PROGRAMMING_WII_FILE_SYSTEM_H 

#include "FileSystem4.h"

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class WiiFileSystem : public FileSystem4
		{
		public:
			virtual char* read(char* path);
			virtual char* write(char* path, char* text);
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_WII_FILE_SYSTEM_H