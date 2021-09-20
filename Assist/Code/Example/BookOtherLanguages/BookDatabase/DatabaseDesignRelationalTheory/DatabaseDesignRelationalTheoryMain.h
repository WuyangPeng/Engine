// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.0 (2020/04/04 19:54)

#ifndef BOOK_DATABASE_DATABASE_DESIGN_RELATIONAL_MAIN_H
#define BOOK_DATABASE_DATABASE_DESIGN_RELATIONAL_MAIN_H

#include "Example/BookOtherLanguages/BookDatabase/BookDatabaseDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookDatabase
{
	 class BOOK_DATABASE_DEFAULT_DECLARE DatabaseDesignRelationalTheoryMain
	 {
	 public:
		 using ClassType = DatabaseDesignRelationalTheoryMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_DATABASE_DATABASE_DESIGN_RELATIONAL_MAIN_H
