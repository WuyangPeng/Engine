///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:46)

#ifndef MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H
#define MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H

#include "Example/BookCpp/MoreEffectiveCpp/MoreEffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace MoreEffectiveCpp
    {
        class GameObject
        {
        public:
            GameObject() = default;
            virtual ~GameObject() noexcept = default;
            GameObject(const GameObject&) = default;
            GameObject& operator=(const GameObject&) = default;
            GameObject(GameObject&&) noexcept = default;
            GameObject& operator=(GameObject&&) noexcept = default;
        };

        class SpaceShip : public GameObject
        {
        };

        class SpaceStation : public GameObject
        {
        };

        class Asteroid : public GameObject
        {
        };

        class Rational
        {
        };

        [[nodiscard]] bool operator==([[maybe_unused]] const Rational& lhs, [[maybe_unused]] const Rational& rhs) noexcept
        {
            return false;
        }
    }
}

#endif  // MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H
