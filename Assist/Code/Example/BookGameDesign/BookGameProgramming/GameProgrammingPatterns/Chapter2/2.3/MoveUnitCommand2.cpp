// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/14 20:55)

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
			// ���ƶ�֮ǰ�����ס��Ԫλ�ã��Ա����ǿ��Խ���ָ���

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


