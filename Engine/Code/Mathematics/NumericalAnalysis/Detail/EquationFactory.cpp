// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:58)

#include "Mathematics/MathematicsExport.h"

#include "EquationFactory.h"
#include "EquationImpl.h"
#include "EquationQuartic.h"
#include "EquationThrice.h"
#include "EquationSecondary.h"
#include "EquationOnce.h"
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;

Mathematics::EquationFactory::EquationImplSharedPtr Mathematics::EquationFactory
	::Create(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
{
	if (epsilon < Mathd::FAbs(quartic))
		return make_shared<EquationQuartic>(constant, once, secondary, thrice, quartic, epsilon);
	else if (epsilon < Mathd::FAbs(thrice))
		return make_shared<EquationThrice>(constant, once, secondary, thrice, epsilon);
	else if (epsilon < Mathd::FAbs(secondary))
		return make_shared<EquationSecondary>(constant, once, secondary, epsilon);
	else
		return  make_shared<EquationOnce>(constant, once, epsilon);
}

