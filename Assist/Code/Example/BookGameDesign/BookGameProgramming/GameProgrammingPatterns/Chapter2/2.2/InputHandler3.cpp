// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/05 22:07)

#include "Command2.h"
#include "InputHandler3.h"

namespace GameProgrammingPatterns
{
    namespace Chapter2
    {
        Command2* InputHandler3::handleInput()
        {
            if (isPressed(BUTTON_X))
            {
                return buttonX_;
            }
            else if (isPressed(BUTTON_Y))
            {
                return buttonY_;
            }
            else if (isPressed(BUTTON_A))
            {
                return buttonA_;
            }
            else if (isPressed(BUTTON_B))
            {
                return buttonB_;
            }

            // Nothing pressed, so do nothing.
            return nullptr;
        }

        bool InputHandler3::isPressed([[maybe_unused]] ButtonType buttonType)
        {
            return false;
        }
    }
}
