// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:09)

#ifndef MATHEMATICS_BASE_FLOAT_1_H
#define MATHEMATICS_BASE_FLOAT_1_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

MATHEMATICS_EXPORT_SHARED_PTR(Float1Impl);

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE Float1
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Float1);

	public:
		Float1();
		explicit Float1(float value);

		CLASS_INVARIANT_DECLARE;

		float GetValue() const;
		void SetValue(float value);

	private:
		IMPL_TYPE_DECLARE(Float1);
	};
}

#endif // MATHEMATICS_BASE_FLOAT_1_H
