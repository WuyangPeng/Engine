/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_SEXAGENARY_CYCLE_BASE_H
#define ANCIENT_BOOKS_SEXAGENARY_CYCLE_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class SexagenaryCycleBase
    {
    public:
        using ClassType = SexagenaryCycleBase;

    public:
        SexagenaryCycleBase() noexcept = default;
        explicit SexagenaryCycleBase(int key) noexcept;

        virtual ~SexagenaryCycleBase() noexcept = default;
        SexagenaryCycleBase(const SexagenaryCycleBase& rhs) noexcept = default;
        SexagenaryCycleBase& operator=(const SexagenaryCycleBase& rhs) noexcept = default;
        SexagenaryCycleBase(SexagenaryCycleBase&& rhs) noexcept = default;
        SexagenaryCycleBase& operator=(SexagenaryCycleBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual System::String GetHeavenly() const;

        NODISCARD virtual System::String GetBranch() const;

        NODISCARD virtual System::String GetName() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_SEXAGENARY_CYCLE_BASE_H
