// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/27 22:31)

#ifndef BOOK_GAME_PROGRAMMING_BULLET1_H 
#define BOOK_GAME_PROGRAMMING_BULLET1_H 

namespace GameProgrammingPatterns
{
	namespace Chapter6
	{
		class Bullet1
		{
		public:
			int getX() const;
			int getY() const;

			void setX(int x);
			void setY(int y);

		private:
			int x_;
			int y_;
		 };
	}
}

#endif // BOOK_GAME_PROGRAMMING_BULLET1_H