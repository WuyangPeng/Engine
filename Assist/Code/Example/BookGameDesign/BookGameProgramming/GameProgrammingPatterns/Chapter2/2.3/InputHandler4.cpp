// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.1.0 (2019/11/14 21:05)

#include "Assist2.3.h"
#include "InputHandler4.h"
#include "MoveUnitCommand1.h"
#include "Example/BookGameDesign/BookGameProgramming/GameProgrammingPatterns/Chapter2/2.1/Command1.h"

namespace GameProgrammingPatterns
{
    namespace Chapter2
    {
        Command1* InputHandler4 ::handleInput()
        {
            Unit* unit = getSelectedUnit();

            if (isPressed(BUTTON_UP))
            {
                // move the unit up one.
                // 将单元向上移动一个

                int destY = unit->y() - 1;
                return new MoveUnitCommand1(unit, unit->x(), destY);
            }

            if (isPressed(BUTTON_DOWN))
            {
                // move the unit down one.
                // 将单元向下移动一个

                int destY = unit->y() - 1;
                return new MoveUnitCommand1(unit, unit->x(), destY);
            }

            // Other moves...
            // 其他移动。

            return nullptr;
        }

        bool InputHandler4::isPressed([[maybe_unused]] ButtonType2 buttonType)
        {
            return false;
        }

        Unit* InputHandler4::getSelectedUnit()
        {
            return nullptr;
        }
    }
}
