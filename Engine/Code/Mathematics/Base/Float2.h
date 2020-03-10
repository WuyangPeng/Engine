// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:22)

#ifndef MATHEMATICS_BASE_FLOAT_2_H
#define MATHEMATICS_BASE_FLOAT_2_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

MATHEMATICS_EXPORT_SHARED_PTR(Float2Impl);

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE Float2
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Float2);

	public:				
		Float2();	
		Float2(float firstValue,float secondValue);

		CLASS_INVARIANT_DECLARE;

		float GetFirstValue() const;
		float GetSecondValue() const;

		void SetFirstValue(float value);
		void SetSecondValue(float value);

	private:	
		IMPL_TYPE_DECLARE(Float2);
	};	
}

#endif // MATHEMATICS_BASE_FLOAT_2_H
