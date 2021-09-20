// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/14 21:05)

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
                // ����Ԫ�����ƶ�һ��

                int destY = unit->y() - 1;
                return new MoveUnitCommand1(unit, unit->x(), destY);
            }

            if (isPressed(BUTTON_DOWN))
            {
                // move the unit down one.
                // ����Ԫ�����ƶ�һ��

                int destY = unit->y() - 1;
                return new MoveUnitCommand1(unit, unit->x(), destY);
            }

            // Other moves...
            // �����ƶ���

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
