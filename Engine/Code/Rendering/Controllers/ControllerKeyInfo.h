// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:32)

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
                ControllerKeyInfo() noexcept;
            ControllerKeyInfo(float normTime, int firstIndex, int secondIndex) noexcept;	

		CLASS_INVARIANT_DECLARE;

		float GetNormTime() const noexcept;
                int GetFirstIndex() const noexcept;
                int GetSecondIndex() const noexcept;

	private:
		float m_NormTime;
		int m_FirstIndex;
		int m_SecondIndex;
	};
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H
