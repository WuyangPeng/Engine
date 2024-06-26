/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:16)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H

#include "CoreTools/CoreToolsDll.h"

#include "ConstObjectAssociated.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <array>
#include <memory>

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(ObjectRegister, ObjectRegisterImpl);

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::ObjectRegister>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::ObjectRegister>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectRegister final : public std::enable_shared_from_this<ObjectRegister>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ObjectRegister);

        using ObjectRegisterSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static ObjectRegisterSharedPtr Create();

    private:
        enum class ObjectRegisterCreate
        {
            Init,
        };

    public:
        explicit ObjectRegister(ObjectRegisterCreate objectRegisterCreate);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetUniqueId(const ConstObjectInterfaceSharedPtr& pointer) const;
        NODISCARD int GetOrderedSize() const;

        NODISCARD int64_t RegisterRoot(const ConstObjectInterfaceSharedPtr& pointer);

        NODISCARD ConstRegisterContainerConstIter begin() const noexcept;
        NODISCARD ConstRegisterContainerConstIter end() const noexcept;

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
        int64_t Register(const T& object);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
        int64_t RegisterWeakPtr(const T& object);

        template <typename T>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
        void RegisterContainer(const T& objects);

        template <typename T, int Size>
        requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType> && 0 <= Size)
        void RegisterContainer(const std::array<T, Size>& objects);

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectRegister);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H
