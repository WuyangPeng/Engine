// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/05 22:07)

#include "Assist2.1.h"
#include "InputHandler1.h"

namespace GameProgrammingPatterns
{
    namespace Chapter2
    {
        void InputHandler1::handleInput()
        {
            if (isPressed(BUTTON_X))
            {
                jump();
            }
            else if (isPressed(BUTTON_Y))
            {
                fireGun();
            }
            else if (isPressed(BUTTON_A))
            {
                swapWeapon();
            }
            else if (isPressed(BUTTON_B))
            {
                lurchIneffectively();
            }
        }

        bool InputHandler1::isPressed([[maybe_unused]] ButtonType buttonType)
        {
            return false;
        }
    }
}
