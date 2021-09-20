// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/05 22:07)

#include "Assist2.1.h"
#include "Command1.h"
#include "InputHandler2.h"

namespace GameProgrammingPatterns
{
    namespace Chapter2
    {
        void InputHandler2::handleInput()
        {
            if (isPressed(BUTTON_X))
            {
                buttonX_->execute();
            }
            else if (isPressed(BUTTON_Y))
            {
                buttonY_->execute();
            }
            else if (isPressed(BUTTON_A))
            {
                buttonA_->execute();
            }
            else if (isPressed(BUTTON_B))
            {
                buttonB_->execute();
            }
        }

        bool InputHandler2::isPressed([[maybe_unused]] ButtonType buttonType)
        {
            return false;
        }
    }
}
