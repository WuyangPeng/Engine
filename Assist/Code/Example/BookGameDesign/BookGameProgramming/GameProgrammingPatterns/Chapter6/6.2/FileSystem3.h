// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/27 22:09)

#ifndef BOOK_GAME_PROGRAMMING_FILE_SYSTEM_3_H 
#define BOOK_GAME_PROGRAMMING_FILE_SYSTEM_3_H 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class FileSystem3
		{
		public:
			virtual ~FileSystem3();
			virtual char* read(char* path) = 0;
			virtual char* write(char* path,char* text) = 0;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_FILE_SYSTEM_3_H