// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/17 21:20)

#ifndef BOOK_GAME_PROGRAMMING_TREE2_H 
#define BOOK_GAME_PROGRAMMING_TREE2_H 

#include "Assist3.1.h"
#include "TreeModel.h"

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{	
		class Tree2
		{
		private:
			TreeModel* model_;

			Vector position_;
			double height_;
			double thickness_;
			Color barkTink_;
			Color leafTint_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_TREE2_H