//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 9:50)

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
        using FactoryFunction = ObjectInterfaceSharedPtr (*)(const BufferSourceSharedPtr& stream);

    public:
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        ObjectInterface() noexcept;
        virtual ~ObjectInterface() noexcept = default;
        ObjectInterface(const ObjectInterface& rhs) noexcept = default;
        virtual ObjectInterface& operator=(const ObjectInterface& rhs) noexcept = default;
        ObjectInterface(ObjectInterface&& rhs) noexcept = default;
        virtual ObjectInterface& operator=(ObjectInterface&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;

    public:
        // 运行时类型信息。
        [[nodiscard]] bool IsExactly(const Rtti& type) const noexcept;
        [[nodiscard]] bool IsDerived(const Rtti& type) const noexcept;
        [[nodiscard]] bool IsExactlyTypeOf(const ObjectInterface* object) const noexcept;
        [[nodiscard]] bool IsDerivedTypeOf(const ObjectInterface* object) const noexcept;

    public:
        // 流
        [[nodiscard]] static bool RegisterFactory();
        static void InitializeFactory();
        static void TerminateFactory();
        [[nodiscard]] static ObjectInterfaceSharedPtr Factory(const CoreTools::BufferSourceSharedPtr& source);

        [[nodiscard]] uint64_t GetUniqueID() const noexcept;
        void SetUniqueID(uint64_t uniqueID) noexcept;

        [[nodiscard]] virtual uint64_t Register(const CoreTools::ObjectRegisterSharedPtr& target) const = 0;
        [[nodiscard]] virtual int GetStreamingSize() const = 0;
        virtual void Save(const CoreTools::BufferTargetSharedPtr& target) const = 0;

        virtual void Link(const CoreTools::ObjectLinkSharedPtr& source) = 0;
        virtual void PostLink() = 0;
        virtual void Load(const CoreTools::BufferSourceSharedPtr& source) = 0;

        [[nodiscard]] virtual ObjectInterfaceSharedPtr CloneObject() const = 0;

    protected:
        // 加载系统所使用的构造函数。
        enum class LoadConstructor
        {
            ConstructorLoader
        };

        explicit ObjectInterface(LoadConstructor value) noexcept;

    private:
        uint64_t m_UniqueID;
    };

    using ObjectInterfaceSharedPtr = ObjectInterface::ObjectInterfaceSharedPtr;
    using ConstObjectInterfaceSharedPtr = ObjectInterface::ConstObjectInterfaceSharedPtr;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ObjectInterface);

#include STSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H
