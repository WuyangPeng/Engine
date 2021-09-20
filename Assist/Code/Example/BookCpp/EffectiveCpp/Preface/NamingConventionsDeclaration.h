///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:46)

#ifndef EFFECTIVE_CPP_PREFACE_NAMING_CONVENTIONS_DECLARATION_H
#define EFFECTIVE_CPP_PREFACE_NAMING_CONVENTIONS_DECLARATION_H

#include "Example/BookCpp/EffectiveCpp/EffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        class Rational
        {
        };

        const Rational operator*(const Rational& lhs, const Rational& rhs);

        class Widget;
        class Airplane;
        class GameCharacter;
    }
}

#endif  // EFFECTIVE_CPP_PREFACE_NAMING_CONVENTIONS_DECLARATION_H
