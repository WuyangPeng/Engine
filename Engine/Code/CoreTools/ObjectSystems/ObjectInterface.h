//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/10 18:25)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#include <memory> 

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::ObjectInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::ObjectInterface>;

namespace CoreTools
{
    using ObjectPtr = ObjectInterface*;

    // ָ������ObjectInterfaceָ��
    using ConstObjectPtr = ObjectInterface const*;

    // ����ObjectInterfaceָ��
    using ObjectConstPtr = ObjectInterface* const;

    // ָ�����ĳ���ObjectInterfaceָ��
    using ConstObjectConstPtr = const ObjectInterface* const;

    class CORE_TOOLS_DEFAULT_DECLARE ObjectInterface : public std::enable_shared_from_this<ObjectInterface>
    {
    public:
        using ClassType = ObjectInterface;
        using ObjectInterfaceSharedPtr = std::shared_ptr<ObjectInterface>;
        using ConstObjectInterfaceSharedPtr = std::shared_ptr<const ObjectInterface>;
        using FactoryFunction = ObjectInterfaceSharedPtr (*)(BufferSource& stream);   

    public:
        ObjectInterface() noexcept;
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26456)
        
        virtual ~ObjectInterface() = default;
        ObjectInterface(const ObjectInterface&) noexcept = default;
        virtual ObjectInterface& operator=(const ObjectInterface&) noexcept = default;
        ObjectInterface(ObjectInterface&&) noexcept = default;
        virtual ObjectInterface& operator=(ObjectInterface&&) noexcept = default;

        #include STSTEM_WARNING_POP

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;

    public:
        // ����ʱ������Ϣ��
        bool IsExactly(const Rtti& type) const noexcept;
        bool IsDerived(const Rtti& type) const noexcept;
        bool IsExactlyTypeOf(const ObjectInterface* object) const noexcept;
        bool IsDerivedTypeOf(const ObjectInterface* object) const noexcept;

    public:
        // ��
        static bool RegisterFactory();
        static void InitializeFactory();
        static void TerminateFactory();
        static ObjectInterfaceSharedPtr Factory(BufferSource& source);

        uint64_t GetUniqueID() const noexcept;
        void SetUniqueID(uint64_t uniqueID) noexcept;

        virtual uint64_t Register(const CoreTools::ObjectRegisterSharedPtr& target) const = 0;
        virtual int GetStreamingSize() const = 0;
        virtual void Save(const CoreTools::BufferTargetSharedPtr& target) const = 0;

        virtual void Link(ObjectLink& source) = 0;
        virtual void PostLink() = 0;
        virtual void Load(BufferSource& source) = 0;

        virtual ObjectInterfaceSharedPtr CloneObject() const = 0;

    protected:
        // ����ϵͳ��ʹ�õĹ��캯����
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
