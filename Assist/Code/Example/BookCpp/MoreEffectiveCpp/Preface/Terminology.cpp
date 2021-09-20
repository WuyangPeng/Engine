///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:47)

#include "Example/BookCpp/MoreEffectiveCpp/MoreEffectiveCppExport.h"

#include "Terminology.h"
#include "TerminologyDeclaration.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/MoreEffectiveCpp/Helper/MoreEffectiveCppClassInvariantMacro.h"

BookExperience::MoreEffectiveCpp::Terminology::Terminology() noexcept
{
    MORE_EFFECTIVE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::MoreEffectiveCpp, Terminology)

void BookExperience::MoreEffectiveCpp::Terminology::Main() const
{
    MORE_EFFECTIVE_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26400)
#include SYSTEM_WARNING_DISABLE(26409)

    GameObject* pgo = new SpaceShip;  // pgo 的静态型别是GameObject*， 动态型别是SpaceShip*
    Asteroid* pa = new Asteroid;  // pa 的静态型别是Asteroid*，动态型别也是Asteroid*。

    delete pgo;
    pgo = pa;  // pgo 的静态型别仍然（永远）是GameObject*，至于其动态型别如今是Asteroid*。

    [[maybe_unused]] const GameObject& rgo = *pa;  // rgo 的静态型别是GameObject，动态型别是Asteroid。
    delete pa;

#include STSTEM_WARNING_POP

    Rational r1, r2;
    if (r1 == r2)
    {
    }
}
