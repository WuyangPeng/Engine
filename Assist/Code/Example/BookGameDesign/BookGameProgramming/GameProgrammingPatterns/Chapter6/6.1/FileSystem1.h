// Copyright (c) 2011-2019
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.1.0 (2019/11/26 21:39)

#ifndef BOOK_GAME_PROGRAMMING_FILE_SYSTEM_1_H 
#define BOOK_GAME_PROGRAMMING_FILE_SYSTEM_1_H 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class FileSystem1
		{
		public:
			static FileSystem1& instance();

		private:
			FileSystem1();

			static FileSystem1* instance_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_FILE_SYSTEM_1_H