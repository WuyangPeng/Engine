// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/19 21:09)

#include "Observer1.h"
#include "Subject1.h"

namespace GameProgrammingPatterns
{
    namespace Chapter4
    {
        void Subject1::addObserver([[maybe_unused]] Observer1* observer)
        {
            // Add to array...
        }

        void Subject1::removeObserver([[maybe_unused]] Observer1* observer)
        {
            // Remove from array...
        }

        void Subject1::notify(const Entity2& entity, Event event)
        {
            for (int i = 0; i < numObservers_; i++)
            {
                observers_[i]->onNotify(entity, event);
            }
        }
    }
}
