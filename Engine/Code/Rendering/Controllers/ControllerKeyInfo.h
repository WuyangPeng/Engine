// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:32)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H
#define RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H 

#include "Rendering/RenderingDll.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ControllerKeyInfo
	{
	public:
		using ClassType = ControllerKeyInfo;
		 
	public:
		ControllerKeyInfo();
		ControllerKeyInfo(float normTime, int firstIndex, int secondIndex);	

		CLASS_INVARIANT_DECLARE;

		float GetNormTime() const;
		int GetFirstIndex() const;
		int GetSecondIndex() const;

	private:
		float m_NormTime;
		int m_FirstIndex;
		int m_SecondIndex;
	};
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H
