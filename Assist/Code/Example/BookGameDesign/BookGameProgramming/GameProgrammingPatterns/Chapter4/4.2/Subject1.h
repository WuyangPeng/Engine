// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/19 21:09)

#ifndef BOOK_GAME_PROGRAMMING_SUBJECT_H 
#define BOOK_GAME_PROGRAMMING_SUBJECT_H  

#include "Assist4.2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{
		class Observer1;

		class Subject1
		{
		public:
			void addObserver(Observer1* observer);
			void removeObserver(Observer1* observer);

			// Other stuff...

		protected:
			void notify(const Entity2& entity, Event event);

		private:
			Observer1* observers_[MAX_OBSERVERS];
			int numObservers_;
		};
	}
}

#endif // BOOK_GAME_PROGRAMMING_SUBJECT_H