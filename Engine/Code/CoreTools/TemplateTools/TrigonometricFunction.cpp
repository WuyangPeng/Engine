// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:45)

#include "CoreTools/CoreToolsExport.h"

#include "TrigonometricFunction.h"

double CoreTools::TrigonometricFunction
	::SineSeries(double radian, int index, int maxTerms) noexcept
{
	if (maxTerms < index)
		return 1.0;

	return 1.0 - (radian * radian / (2.0 * index + 2.0) / (2.0 * index + 3.0) * SineSeries(radian, index + 1, maxTerms));
}

double CoreTools::TrigonometricFunction
	::RecursiveSine(double radian) noexcept
{
	constexpr auto maxTerms = 10;

	return radian * SineSeries(radian, 0, maxTerms);
}

double CoreTools::TrigonometricFunction
	::NonRecursiveSine(double radian) noexcept
{
	auto radianSqrare = radian * radian;

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
