//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 11:33)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H

#include "CoreTools/CoreToolsDll.h"

#include "ConstObjectAssociated.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <array>
#include <memory>

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectRegisterImpl);

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::ObjectRegister>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::ObjectRegister>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectRegister final : public std::enable_shared_from_this<ObjectRegister>
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ObjectRegister);

    public:
        explicit ObjectRegister(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t GetUniqueID(const ConstObjectInterfaceSharedPtr& smartPointer) const;
        [[nodiscard]] int GetOrderedSize() const;

        [[nodiscard]] uint64_t RegisterRoot(const ConstObjectInterfaceSharedPtr& smartPointer);

        [[nodiscard]] ConstRegisterContainerConstIter begin() const noexcept;
        [[nodiscard]] ConstRegisterContainerConstIter end() const noexcept;

        template <typename T>
        void Register(const T& object);

        template <typename T>
        void RegisterContainer(const T& objects);

        template <typename T, int Size>
        void RegisterContainer(const std::array<T, Size>& objects);

    private:
        IMPL_TYPE_DECLARE(ObjectRegister);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectRegister);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H
