///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/25 16:04)

#ifndef CORE_TOOLS_CONTRACT_SHARED_IMPL_H
#define CORE_TOOLS_CONTRACT_SHARED_IMPL_H

#include "ContractFwd.h"
#include "ImplStaticAssertHelper.h"
#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    // ����빲����Դ������ֻ�Ǹ������ָ���Ա�����й����������Shared��Ϊ��׺��
    template <typename T>
    class SharedImpl final
    {
    public:
        using ClassType = SharedImpl<T>;
        using ClassShareType = CoreTools::ShareClasses;
        using SharedPtr = std::shared_ptr<T>;
        using ConstSharedPtr = std::shared_ptr<const T>;

    public:
        SharedImpl() noexcept = delete;

        template <typename Type, typename... Types>
        explicit SharedImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit SharedImpl(MAYBE_UNUSED ImplCreateUseFactory ImplCreateType, Types&&... args);

        template <typename... Types>
        explicit SharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSharedPtr operator->() const noexcept;
        NODISCARD SharedPtr operator->() noexcept;
        NODISCARD const T& operator*() const noexcept;
        NODISCARD T& operator*() noexcept;

    private:
        SharedPtr impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SHARED_IMPL_H
