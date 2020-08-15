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

 
