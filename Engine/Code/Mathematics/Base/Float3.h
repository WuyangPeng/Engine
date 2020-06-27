// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:09)

#ifndef MATHEMATICS_BASE_FLOAT_3_H
#define MATHEMATICS_BASE_FLOAT_3_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

MATHEMATICS_EXPORT_SHARED_PTR(Float3Impl);

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE Float3
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Float3);

	public:
		Float3();
		Float3(float firstValue, float secondValue, float thirdValue);

		CLASS_INVARIANT_DECLARE;

		float GetFirstValue() const;
		float GetSecondValue() const;
		float GetThirdValue() const;

		void SetFirstValue(float value);
		void SetSecondValue(float value);
		void SetThirdValue(float value);

	private:
		IMPL_TYPE_DECLARE(Float3);
	};
}

#endif // MATHEMATICS_BASE_FLOAT_3_H
