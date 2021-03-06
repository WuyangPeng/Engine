// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 10:31)

#include "Rendering/RenderingExport.h"

#include "BspNode.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
 
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
 #include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486) 
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, BspNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BspNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BspNode); 

Rendering::BspNode
	::BspNode ()
    : ModelPlane(0.0f, 0.0f, 0.0f, 0.0f),mWorldPlane(0.0f, 0.0f, 0.0f, 0.0f)
{
	SpatialSharedPtr spatialSharedPtr;
	AttachChild(spatialSharedPtr);  // left child
	AttachChild(spatialSharedPtr);  // middle child
	AttachChild(spatialSharedPtr);  // right child
}

Rendering::BspNode
	::BspNode(const Mathematics::FloatPlane& modelPlane)
    :ModelPlane(modelPlane),mWorldPlane(modelPlane)
{
	SpatialSharedPtr spatialSharedPtr;
	AttachChild(spatialSharedPtr);  // left child
	AttachChild(spatialSharedPtr);  // middle child
	AttachChild(spatialSharedPtr);  // right child
}

 

Rendering::SpatialSharedPtr Rendering::BspNode
	::GetContainingNode(const Mathematics::FloatAPoint& point)
{
    SpatialSharedPtr posChild = GetPositiveChild();
	SpatialSharedPtr negChild = GetNegativeChild();

	if (posChild  || negChild )
    {
		BspNodeSharedPtr bspChild;

        if (mWorldPlane.WhichSide(point) < Mathematics::NumericalValueSymbol::Zero)
        {
            bspChild = boost::polymorphic_pointer_cast<BspNode>(negChild);//.PolymorphicCastObjectSharedPtr<SharedPtr>();
			if (bspChild )
            {
                return bspChild->GetContainingNode(point);
            }
            else
            {
                return negChild;
            }
        }
        else
        {
            bspChild = boost::polymorphic_pointer_cast<BspNode>(negChild);
           // posChild.PolymorphicCastObjectSharedPtr<BspNodeSharedPtr>();
			if (bspChild )
            {
                return bspChild->GetContainingNode(point);
            }
            else
            {
                return posChild;
            }
        }
    }

	return SpatialSharedPtr(this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BspNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

bool Rendering::BspNode::UpdateWorldData (double applicationTime)
{
const	bool result =  Node::UpdateWorldData(applicationTime);
 
     //mWorldPlane = ModelPlane * GetWorldTransform().GetInverseMatrix();
  // mWorldPlane.Normalize();

	return result;
}

void Rendering::BspNode
	::GetVisibleSet (Culler& culler, bool noCull)
{
    // Get visible Geometry in back-to-front order.  If a global effect is
    // active, the Geometry objects in the subtree will be drawn using it.
    SpatialSharedPtr posChild = GetPositiveChild();
	SpatialSharedPtr copChild = GetCoplanarChild();
	SpatialSharedPtr negChild = GetNegativeChild();

    const ConstCameraSharedPtr camera = culler.GetCamera();
	Mathematics::NumericalValueSymbol positionSide = mWorldPlane.WhichSide(camera->GetPosition());
const	Mathematics::NumericalValueSymbol frustumSide = culler.WhichSide(mWorldPlane);

    if (positionSide > Mathematics::NumericalValueSymbol::Zero)
    {
        // Camera origin on positive side of plane.

        if (frustumSide <= Mathematics::NumericalValueSymbol::Zero)
        {
            // The frustum is on the negative side of the plane or straddles
            // the plane.  In either case, the negative child is potentially
            // visible.
			if (negChild )
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide == Mathematics::NumericalValueSymbol::Zero)
        {
            // The frustum straddles the plane.  The coplanar child is
            // potentially visible.
			if (copChild )
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide >= Mathematics::NumericalValueSymbol::Zero)
        {
            // The frustum is on the positive side of the plane or straddles
            // the plane.  In either case, the positive child is potentially
            // visible.
			if (posChild )
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }
        }
    }
    else if (positionSide < Mathematics::NumericalValueSymbol::Zero)
    {
        // Camera origin on negative side of plane.

        if (frustumSide >= Mathematics::NumericalValueSymbol::Zero)
        {
            // The frustum is on the positive side of the plane or straddles
            // the plane.  In either case, the positive child is potentially
            // visible.
			if (posChild )
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide == Mathematics::NumericalValueSymbol::Zero)
        {
            // The frustum straddles the plane.  The coplanar child is
            // potentially visible.
			if (copChild )
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide <= Mathematics::NumericalValueSymbol::Zero)
        {
            // The frustum is on the negative side of the plane or straddles
            // the plane.  In either case, the negative child is potentially
            // visible.
			if (negChild )
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }
        }
    }
    else
    {
        // Camera origin on plane itself.  Both sides of the plane are
        // potentially visible as well as the plane itself.  Select the
        // first-to-be-drawn half space to be the one to which the camera
        // direction points.
		float NdD = Dot( mWorldPlane.GetNormal(),camera->GetDirectionVector());
        if (NdD >= 0.0f)
        {
			if (posChild )
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }

			if (copChild )
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }

			if (negChild )
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }
        }
        else
        {
			if (negChild )
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }

			if (copChild )
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }

			if (posChild )
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }
        }
    }
}



// Streaming support.

Rendering::BspNode
	::BspNode (LoadConstructor value)
    : Node(value), ModelPlane(0.0f, 0.0f, 0.0f, 0.0f), mWorldPlane(0.0f, 0.0f, 0.0f, 0.0f)
{
}

void Rendering::BspNode
	::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Node::Load(source);

    source->ReadAggregate(ModelPlane);
    source->ReadAggregate(mWorldPlane);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BspNode
	::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    Node::Link(source);
}

void Rendering::BspNode
	::PostLink ()
{
    Node::PostLink();
}

uint64_t Rendering::BspNode
	::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    return Node::Register(target);
}

void Rendering::BspNode
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Node::Save(target);

	target->WriteAggregate(ModelPlane);
    target->WriteAggregate(mWorldPlane);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::BspNode
	::GetStreamingSize () const
{
    int size = Node::GetStreamingSize();
    size += sizeof(ModelPlane);
    size += sizeof(mWorldPlane);
    return size;
}


Rendering::SpatialSharedPtr Rendering::BspNode
	::AttachPositiveChild (SpatialSharedPtr child)
{
	AttachChild(child);
	return child;
	 
	//return SetChild(0, child);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::AttachCoplanarChild(SpatialSharedPtr child)
{
	AttachChild(child);
	return child;
	 
	//return SetChild(1, child);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::AttachNegativeChild(SpatialSharedPtr child)
 {
	 AttachChild(child);
	 return child;
	 
	//return SetChild(2, child);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::DetachPositiveChild()
{
	return DetachChildAt(0);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::DetachCoplanarChild()
{
	return DetachChildAt(1);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::DetachNegativeChild()
{
	return DetachChildAt(2);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::GetPositiveChild()
{
	return GetChild(0);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::GetCoplanarChild()
{
	return GetChild(1);
}

Rendering::SpatialSharedPtr Rendering::BspNode
	::GetNegativeChild()
{
	return GetChild(2);
}

 const Mathematics::FloatPlane& Rendering::BspNode
	 ::GetWorldPlane() const noexcept
{
	return mWorldPlane;
}

	#include STSTEM_WARNING_POP