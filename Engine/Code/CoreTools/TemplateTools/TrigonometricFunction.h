// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:42)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H
#define CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	namespace TrigonometricFunction
	{
		// µ›πÈ Sine
		double CORE_TOOLS_DEFAULT_DECLARE SineSeries(double radian, int index, int maxTerms) noexcept;
		double CORE_TOOLS_DEFAULT_DECLARE RecursiveSine( double radian ) noexcept;

		// ∑«µ›πÈ Sine
		constexpr double NonRecursiveSine( double radian ) noexcept
		{
			const auto radianSqrare = radian * radian;

			return radian * (1.0 - radianSqrare / 2.0 / 3.0 *
				(1.0 - radianSqrare / 4.0 / 5.0 *
					(1.0 - radianSqrare / 6.0 / 7.0 *
						(1.0 - radianSqrare / 8.0 / 9.0 *
							(1.0 - radianSqrare / 10.0 / 11.0 *
								(1.0 - radianSqrare / 12.0 / 13.0 *
									(1.0 - radianSqrare / 14.0 / 15.0 *
										(1.0 - radianSqrare / 16.0 / 17.0 *
											(1.0 - radianSqrare / 18.0 / 19.0 *
												(1.0 - radianSqrare / 20.0 / 21.0))))))))));
		}
	}	
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H
