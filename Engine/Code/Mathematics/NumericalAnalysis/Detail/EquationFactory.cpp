/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:31)

#include "Mathematics/MathematicsExport.h"

#include "EquationFactory.h"
#include "EquationImpl.h"
#include "EquationOnce.h"
#include "EquationQuartic.h"
#include "EquationSecondary.h"
#include "EquationThrice.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::EquationFactory::EquationImplSharedPtr Mathematics::EquationFactory::Create(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
{
    if (epsilon < MathD::FAbs(quartic))
        return std::make_shared<EquationQuartic>(constant, once, secondary, thrice, quartic, epsilon);
    else if (epsilon < MathD::FAbs(thrice))
        return std::make_shared<EquationThrice>(constant, once, secondary, thrice, epsilon);
    else if (epsilon < MathD::FAbs(secondary))
        return std::make_shared<EquationSecondary>(constant, once, secondary, epsilon);
    else
        return std::make_shared<EquationOnce>(constant, once, epsilon);
}
