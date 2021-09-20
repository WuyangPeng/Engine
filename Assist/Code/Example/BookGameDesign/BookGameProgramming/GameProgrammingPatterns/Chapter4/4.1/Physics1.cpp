// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/18 23:35)

#include "Assist4.1.h"
#include "Physics1.h"

namespace GameProgrammingPatterns
{
    namespace Chapter4
    {
        void Physics1::updateEntity(Entity1& entity)
        {
            bool wasOnSurface = entity.isOnSurface();
            entity.accelerate(GRAVITY);
            entity.update();

            if (wasOnSurface && !entity.isOnSurface())
            {
                notify(entity, EVENT_START_FALL);
            }
        }

        void Physics1::notify([[maybe_unused]] Entity1& entity, [[maybe_unused]] int eventStartFall)
        {
        }
    }
}
