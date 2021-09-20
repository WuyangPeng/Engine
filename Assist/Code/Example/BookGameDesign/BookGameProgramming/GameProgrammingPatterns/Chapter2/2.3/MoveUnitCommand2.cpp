// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.1.0 (2019/11/14 20:55)

#include "MoveUnitCommand2.h"   
#include "Assist2.3.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{		
		MoveUnitCommand2::MoveUnitCommand2(Unit* unit, int x, int y)
			:unit_(unit),x_(x),y_(y), xBefore_(0),yBefore_(0)
		{

		}

		void MoveUnitCommand2::execute()
		{
			// Remember the unit'sposition before the move
			// so we can restore it.
			// 在移动之前，请记住单元位置，以便我们可以将其恢复。

			xBefore_ = unit_->x();
			yBefore_ = unit_->y();
			unit_->moveTo(x_, y_);
		}

		void MoveUnitCommand2::undo()
		{
			unit_->moveTo(xBefore_, yBefore_);
		}
	}
}


