///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:47)

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

    GameObject* pgo = new SpaceShip;  // pgo �ľ�̬�ͱ���GameObject*�� ��̬�ͱ���SpaceShip*
    Asteroid* pa = new Asteroid;  // pa �ľ�̬�ͱ���Asteroid*����̬�ͱ�Ҳ��Asteroid*��

    delete pgo;
    pgo = pa;  // pgo �ľ�̬�ͱ���Ȼ����Զ����GameObject*�������䶯̬�ͱ������Asteroid*��

    [[maybe_unused]] const GameObject& rgo = *pa;  // rgo �ľ�̬�ͱ���GameObject����̬�ͱ���Asteroid��
    delete pa;

#include STSTEM_WARNING_POP

    Rational r1, r2;
    if (r1 == r2)
    {
    }
}
