// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/16 18:55)

#ifndef BOOK_GAME_PROGRAMMING_TREE1_H 
#define BOOK_GAME_PROGRAMMING_TREE1_H 

#include "Assist3.1.h"

namespace GameProgrammingPatterns
{
	namespace Chapter3
	{	
		class Tree1
		{
		private:
			Mesh mesh_;
			Texture1 bark_;
			Texture1 leaves_;
			Vector position_;
			double height_;
			double thickness_;
			Color barkTink_;
			Color leafTint_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_TREE1_H