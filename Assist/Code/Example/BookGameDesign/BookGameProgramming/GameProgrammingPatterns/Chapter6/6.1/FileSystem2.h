// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/26 21:39)

#ifndef BOOK_GAME_PROGRAMMING_FILE_SYSTEM_2_H 
#define BOOK_GAME_PROGRAMMING_FILE_SYSTEM_2_H 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class FileSystem2
		{
		public:
			static FileSystem2& instance();

		private:
			FileSystem2(); 
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_FILE_SYSTEM_2_H