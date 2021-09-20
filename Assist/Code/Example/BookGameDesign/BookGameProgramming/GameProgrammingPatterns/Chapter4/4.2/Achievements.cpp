// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/19 21:09)

#include "Achievements.h"
#include "Assist4.2.h"

namespace GameProgrammingPatterns
{
    namespace Chapter4
    {
        void Achievements::onNotify(const Entity2& entity, Event event)
        {
            switch (event)
            {
                case Event::EVENT_ENTITY_FELL:
                    if (entity.isHero() && heroIsOnBridge_)
                    {
                        unlock(Achievement::ACHIEVEMENT_FILL_OFF_BRIDGE);
                    }
                    break;

                    // Handle other events...
                    // Update heroIsOnBridge_...
                default:
                    break;
            }
        }

        void Achievements::unlock([[maybe_unused]] Achievement achievement)
        {
            // Unlock if not already unlocked...
        }
    }
}
