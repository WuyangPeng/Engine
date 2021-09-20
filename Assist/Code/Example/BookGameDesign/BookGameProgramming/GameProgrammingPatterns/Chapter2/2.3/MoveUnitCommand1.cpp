// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.1.0 (2019/11/14 20:55)

#include "MoveUnitCommand1.h"   
#include "Assist2.3.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{		
		MoveUnitCommand1::MoveUnitCommand1(Unit* unit, int x, int y)
			:unit_(unit),x_(x),y_(y)
		{

		}

		void MoveUnitCommand1::execute()
		{
			unit_->moveTo(x_, y_);
		}
	}
}


