///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/13 14:42)

#include "Mathematics/MathematicsExport.h"

#include "EquationFactory.h"
#include "EquationImpl.h"
#include "EquationOnce.h"
#include "EquationQuartic.h"
#include "EquationSecondary.h"
#include "EquationThrice.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Mathematics::EquationFactory::EquationImplSharedPtr Mathematics::EquationFactory::Create(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
{
    if (epsilon < MathD::FAbs(quartic))
        return make_shared<EquationQuartic>(constant, once, secondary, thrice, quartic, epsilon);
    else if (epsilon < MathD::FAbs(thrice))
        return make_shared<EquationThrice>(constant, once, secondary, thrice, epsilon);
    else if (epsilon < MathD::FAbs(secondary))
        return make_shared<EquationSecondary>(constant, once, secondary, epsilon);
    else
        return make_shared<EquationOnce>(constant, once, epsilon);
}
