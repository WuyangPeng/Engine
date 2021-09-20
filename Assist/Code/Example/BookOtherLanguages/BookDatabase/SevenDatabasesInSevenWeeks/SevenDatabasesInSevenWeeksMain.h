// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.0 (2020/04/04 20:23)

#ifndef BOOK_DATABASE_SEVEN_DATABASES_IN_SEVEN_WEEKS_MAIN_H
#define BOOK_DATABASE_SEVEN_DATABASES_IN_SEVEN_WEEKS_MAIN_H

#include "Example/BookOtherLanguages/BookDatabase/BookDatabaseDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookDatabase
{
	 class BOOK_DATABASE_DEFAULT_DECLARE SevenDatabasesInSevenWeeksMain
	 {
	 public:
		 using ClassType = SevenDatabasesInSevenWeeksMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_DATABASE_SEVEN_DATABASES_IN_SEVEN_WEEKS_MAIN_H
