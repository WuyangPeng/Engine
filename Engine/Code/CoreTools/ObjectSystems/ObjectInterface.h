/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:55)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::ObjectInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::ObjectInterface>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectInterface : public std::enable_shared_from_this<ObjectInterface>
    {
    public:
        using ClassType = ObjectInterface;
        CORE_TOOLS_SHARED_PTR_DECLARE(ObjectInterface);
        using FactoryFunction = ObjectInterfaceSharedPtr (*)(BufferSource& stream);

    public:
        ObjectInterface() noexcept;
        explicit ObjectInterface(int64_t uniqueId) noexcept;
        virtual ~ObjectInterface() noexcept = default;
        ObjectInterface(const ObjectInterface& rhs) noexcept = default;
        ObjectInterface& operator=(const ObjectInterface& rhs) noexcept = default;
        ObjectInterface(ObjectInterface&& rhs) noexcept = default;
        ObjectInterface& operator=(ObjectInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;

    public:
        // 运行时类型信息。
        NODISCARD bool IsExactly(const Rtti& type) const noexcept;
        NODISCARD bool IsDerived(const Rtti& type) const noexcept;
        NODISCARD bool IsExactlyTypeOf(const ObjectInterface* object) const noexcept;
        NODISCARD bool IsDerivedTypeOf(const ObjectInterface* object) const noexcept;

    public:
        // 流
        NODISCARD static bool RegisterFactory();
        static void InitializeFactory();
        static void TerminateFactory();
        NODISCARD static ObjectInterfaceSharedPtr Factory(BufferSource& source);

        NODISCARD int64_t GetUniqueId() const noexcept;
        void SetUniqueId(int64_t aUniqueId) noexcept;

        NODISCARD virtual int64_t Register(ObjectRegister& target) const = 0;
        NODISCARD virtual int GetStreamingSize() const = 0;
        virtual void Save(BufferTarget& target) const = 0;

        virtual void Link(ObjectLink& source) = 0;
        virtual void PostLink() = 0;
        virtual void Load(BufferSource& source) = 0;

        NODISCARD virtual ObjectInterfaceSharedPtr CloneObject() const = 0;

    protected:
        // 加载系统所使用的构造函数。
        enum class LoadConstructor
        {
            ConstructorLoader
        };

        explicit ObjectInterface(LoadConstructor loadConstructor) noexcept;

    private:
        int64_t uniqueId;
    };

    using ObjectInterfaceSharedPtr = ObjectInterface::ObjectInterfaceSharedPtr;
    using ConstObjectInterfaceSharedPtr = ObjectInterface::ConstObjectInterfaceSharedPtr;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ObjectInterface);

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H
