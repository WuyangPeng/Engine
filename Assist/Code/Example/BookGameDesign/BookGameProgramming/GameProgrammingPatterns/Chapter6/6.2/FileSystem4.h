// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/27 22:09)

#ifndef BOOK_GAME_PROGRAMMING_FILE_SYSTEM_4_H 
#define BOOK_GAME_PROGRAMMING_FILE_SYSTEM_4_H 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class FileSystem4
		{
		public:
			static FileSystem4& instance();

			virtual ~FileSystem4();
			virtual char* read(char* path) = 0;
			virtual char* write(char* path,char* text) = 0;

		protected:
			FileSystem4();
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_FILE_SYSTEM_4_H