// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_FACTORY_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_FACTORY_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h" 

#include <memory>

namespace Mathematics
{
	class EquationImpl;

	class MATHEMATICS_HIDDEN_DECLARE EquationFactory
	{
	public:
		using ClassType = EquationFactory;
		using EquationImplSharedPtr = std::shared_ptr<EquationImpl>;

	public:
		static EquationImplSharedPtr Create(double constant, double once, double secondary = 0.0, double thrice = 0.0, double quartic = 0.0, double epsilon = Mathd::GetZeroTolerance());
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_FACTORY_H


