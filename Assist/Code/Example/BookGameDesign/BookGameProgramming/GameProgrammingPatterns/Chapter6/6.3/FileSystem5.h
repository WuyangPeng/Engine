// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/27 22:09)

#ifndef BOOK_GAME_PROGRAMMING_FILE_SYSTEM_5_H 
#define BOOK_GAME_PROGRAMMING_FILE_SYSTEM_5_H 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class FileSystem5
		{
		public:
			static FileSystem5& instance();

		private:
			FileSystem5(); 

			static FileSystem5 instance_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_FILE_SYSTEM_5_H