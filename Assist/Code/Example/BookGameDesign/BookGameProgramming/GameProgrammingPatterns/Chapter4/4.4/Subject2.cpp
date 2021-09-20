// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/19 21:09)

#include "Subject2.h" 
#include "Observer2.h"

namespace GameProgrammingPatterns
{
	namespace Chapter4
	{			 
		void Subject2::addObserver(Observer2* observer)
		{
			observer->next_ = head_;
			head_ = observer;
		}

		void Subject2::removeObserver(Observer2* observer)
		{
			if (head_ == observer)
			{
				head_ = observer->next_;
				observer->next_ = nullptr;
				return;
			}

			Observer2* current = head_;
			while (current != nullptr)
			{
				if (current->next_ == observer)
				{
					current->next_ = observer->next_;
					observer->next_ = nullptr;
					return;
				}

				current = current->next_;
			}
		}

		void Subject2::notify(const Entity2& entity, Event event)
		{
			Observer2* observer = head_;
			while (observer != nullptr)
			{
				observer->onNotify(entity, event);
				observer = observer->next_;
			}
		}
	}
}


