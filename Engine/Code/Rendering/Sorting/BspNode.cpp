// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:31)

#include "Rendering/RenderingExport.h"

#include "BspNode.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h" 
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
 #include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486) 
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, BspNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BspNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BspNode); 

Rendering::BspNode
	::BspNode ()
    : ModelPlane(0.0f, 0.0f, 0.0f, 0.0f),mWorldPlane(0.0f, 0.0f, 0.0f, 0.0f)
{
	SpatialSmartPointer spatialSmartPointer;
	AttachChild(spatialSmartPointer);  // left child
	AttachChild(spatialSmartPointer);  // middle child
	AttachChild(spatialSmartPointer);  // right child
}

Rendering::BspNode
	::BspNode(const Mathematics::Planef& modelPlane)
    :ModelPlane(modelPlane),mWorldPlane(modelPlane)
{
	SpatialSmartPointer spatialSmartPointer;
	AttachChild(spatialSmartPointer);  // left child
	AttachChild(spatialSmartPointer);  // middle child
	AttachChild(spatialSmartPointer);  // right child
}

 

Rendering::SpatialSmartPointer Rendering::BspNode
	::GetContainingNode(const Mathematics::APointf& point)
{
    SpatialSmartPointer posChild = GetPositiveChild();
	SpatialSmartPointer negChild = GetNegativeChild();

	if (posChild  || negChild )
    {
		BspNodeSmartPointer bspChild;

        if (mWorldPlane.WhichSide(point) < Mathematics::NumericalValueSymbol::Zero)
        {
            bspChild = boost::polymorphic_pointer_cast<BspNode>(negChild);//.PolymorphicCastObjectSmartPointer<SmartPointer>();
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
           // posChild.PolymorphicCastObjectSmartPointer<BspNodeSmartPointer>();
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

	return SpatialSmartPointer(this);
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
    SpatialSmartPointer posChild = GetPositiveChild();
	SpatialSmartPointer copChild = GetCoplanarChild();
	SpatialSmartPointer negChild = GetNegativeChild();

    const ConstCameraSmartPointer camera = culler.GetCamera();
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
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Node::Load(source);

    source.ReadAggregate(ModelPlane);
    source.ReadAggregate(mWorldPlane);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BspNode
	::Link(CoreTools::ObjectLink& source)
{
    Node::Link(source);
}

void Rendering::BspNode
	::PostLink ()
{
    Node::PostLink();
}

uint64_t Rendering::BspNode
	::Register(CoreTools::ObjectRegister& target) const
{
    return Node::Register(target);
}

void Rendering::BspNode
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Node::Save(target);

	target.WriteAggregate(ModelPlane);
    target.WriteAggregate(mWorldPlane);

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


Rendering::SpatialSmartPointer Rendering::BspNode
	::AttachPositiveChild (SpatialSmartPointer child)
{
	AttachChild(child);
	return child;
	 
	//return SetChild(0, child);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::AttachCoplanarChild(SpatialSmartPointer child)
{
	AttachChild(child);
	return child;
	 
	//return SetChild(1, child);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::AttachNegativeChild(SpatialSmartPointer child)
 {
	 AttachChild(child);
	 return child;
	 
	//return SetChild(2, child);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::DetachPositiveChild()
{
	return DetachChildAt(0);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::DetachCoplanarChild()
{
	return DetachChildAt(1);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::DetachNegativeChild()
{
	return DetachChildAt(2);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::GetPositiveChild()
{
	return GetChild(0);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::GetCoplanarChild()
{
	return GetChild(1);
}

Rendering::SpatialSmartPointer Rendering::BspNode
	::GetNegativeChild()
{
	return GetChild(2);
}

 const Mathematics::Planef& Rendering::BspNode
	 ::GetWorldPlane() const noexcept
{
	return mWorldPlane;
}

	#include STSTEM_WARNING_POP