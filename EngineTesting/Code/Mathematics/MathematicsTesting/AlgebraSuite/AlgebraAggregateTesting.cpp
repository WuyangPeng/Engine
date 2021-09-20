// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:18)

#include "AlgebraAggregateTesting.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"

#include <random>  

using std::vector;
using std::make_shared;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,AlgebraAggregateTesting) 

void Mathematics::AlgebraAggregateTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(HomogeneousPointTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Vector2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Vector3DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Vector4DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AVectorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(APointTest);
	ASSERT_NOT_THROW_EXCEPTION_0(VariableLengthVectorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PolynomialTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Matrix2Test);
	ASSERT_NOT_THROW_EXCEPTION_0(Matrix3Test);
	ASSERT_NOT_THROW_EXCEPTION_0(Matrix4Test);
	ASSERT_NOT_THROW_EXCEPTION_0(MatrixTest);
	ASSERT_NOT_THROW_EXCEPTION_0(VariableMatrixTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BandedMatrixTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BandedMatrixSolveTest);
	ASSERT_NOT_THROW_EXCEPTION_0(QuaternionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AQuaternionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Float1Test);
	ASSERT_NOT_THROW_EXCEPTION_0(Float2Test);
	ASSERT_NOT_THROW_EXCEPTION_0(Float3Test);
	ASSERT_NOT_THROW_EXCEPTION_0(Float4Test);
}

void Mathematics::AlgebraAggregateTesting
	::HomogeneousPointTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 }; 
// 
// 	auto maxSize = MATHEMATICS_STREAM_SIZE(FloatHomogeneousPoint()) + MATHEMATICS_STREAM_SIZE(DoubleHomogeneousPoint());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 		int currentWriteBufferSize{ 0 };
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatHomogeneousPoint firstHomogeneousPoint{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstHomogeneousPoint);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstHomogeneousPoint);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleHomogeneousPoint secondHomogeneousPoint{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondHomogeneousPoint);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondHomogeneousPoint);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatHomogeneousPoint thirdHomogeneousPoint;
// 
// 	    source.ReadAggregate(thirdHomogeneousPoint);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdHomogeneousPoint);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstHomogeneousPoint,thirdHomogeneousPoint,1e-8f));
// 
// 	    DoubleHomogeneousPoint fourthHomogeneousPoint;
// 
// 	    source.ReadAggregate(fourthHomogeneousPoint);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthHomogeneousPoint);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondHomogeneousPoint, fourthHomogeneousPoint,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Vector2DTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
//  
// 	auto maxSize = MATHEMATICS_STREAM_SIZE(FloatVector2D()) + MATHEMATICS_STREAM_SIZE(DoubleVector2D());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) }; 
// 
// 	    // –¥
// 		int currentWriteBufferSize{ 0 };
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatVector2D firstVector2D{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstVector2D);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstVector2D);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleVector2D secondVector2D{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondVector2D);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondVector2D);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatVector2D thirdVector2D;
// 
// 	    source.ReadAggregate(thirdVector2D);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdVector2D);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(FloatVector2DTools::Approximate(firstVector2D,thirdVector2D,1e-8f));
// 
// 	    DoubleVector2D fourthVector2D;
// 
// 	    source.ReadAggregate(fourthVector2D);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthVector2D);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(DoubleVector2DTools::Approximate(secondVector2D, fourthVector2D,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Vector3DTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 
// 	auto maxSize = MATHEMATICS_STREAM_SIZE(FloatVector3D()) + MATHEMATICS_STREAM_SIZE(DoubleVector3D());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 		int currentWriteBufferSize{ 0 };
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatVector3D firstVector3D{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstVector3D);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstVector3D);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleVector3D secondVector3D{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondVector3D);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondVector3D);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatVector3D thirdVector3D;
// 
// 	    source.ReadAggregate(thirdVector3D);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdVector3D);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3D,thirdVector3D,1e-8f));
// 
// 	    DoubleVector3D fourthVector3D;
// 
// 	    source.ReadAggregate(fourthVector3D);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthVector3D);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(DoubleVector3DTools::Approximate(secondVector3D, fourthVector3D,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Vector4DTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 
// 	auto maxSize = MATHEMATICS_STREAM_SIZE(FloatVector4D()) + MATHEMATICS_STREAM_SIZE(DoubleVector4D());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatVector4D firstVector4D{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstVector4D);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstVector4D);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleVector4D secondVector4D{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondVector4D);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondVector4D);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatVector4D thirdVector4D;
// 
// 	    source.ReadAggregate(thirdVector4D);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdVector4D);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(FloatVector4DTools::Approximate(firstVector4D,thirdVector4D,1e-8f));
// 
// 	    DoubleVector4D fourthVector4D;
// 
// 	    source.ReadAggregate(fourthVector4D);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthVector4D);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(DoubleVector4DTools::Approximate(secondVector4D, fourthVector4D,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::AVectorTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 
// 	auto maxSize = MATHEMATICS_STREAM_SIZE(FloatAVector()) + MATHEMATICS_STREAM_SIZE(DoubleAVector());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatAVector firstAVector{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstAVector);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstAVector);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleAVector secondAVector{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondAVector);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondAVector);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatAVector thirdAVector;
// 
// 	    source.ReadAggregate(thirdAVector);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdAVector);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstAVector, thirdAVector,1e-8f));
//  
// 	    DoubleAVector fourthAVector;
// 
// 	    source.ReadAggregate(fourthAVector);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthAVector);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondAVector, fourthAVector,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::APointTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 
// 	auto maxSize = MATHEMATICS_STREAM_SIZE(FloatAPoint()) + MATHEMATICS_STREAM_SIZE(DoubleAPoint());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 		int currentWriteBufferSize{ 0 };
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatAPoint firstAPoint{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstAPoint);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstAPoint);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleAPoint secondAPoint{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondAPoint);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondAPoint);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatAPoint thirdAPoint;
// 
// 	    source.ReadAggregate(thirdAPoint);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdAPoint);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstAPoint, thirdAPoint,1e-8f));
// 
// 	    DoubleAPoint fourthAPoint;
// 
// 	    source.ReadAggregate(fourthAPoint);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthAPoint);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondAPoint, fourthAPoint,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::VariableLengthVectorTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	uniform_int<> intRandomDistribution(1,20);
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 	    int firstLength = intRandomDistribution(randomEngine);
// 	    int secondLength = intRandomDistribution(randomEngine);
// 
// 	    int maxSize = MATHEMATICS_STREAM_SIZE(FloatVariableLengthVector(firstLength)) + MATHEMATICS_STREAM_SIZE(DoubleVariableLengthVector(secondLength));
// 
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 		int currentWriteBufferSize{ 0 };
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    vector<float> floatVector;
// 	    for(int k = 0;k < firstLength;++k)
// 	    {
// 		     floatVector.push_back(floatRandomDistribution(randomEngine));
// 	    }
// 
// 		FloatVariableLengthVector firstVariableLengthVector{ floatVector };
// 
// 	    target.WriteAggregate(firstVariableLengthVector);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstVariableLengthVector);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    vector<double> doubleVector;
// 	    for(int k = 0;k < secondLength;++k)
// 	    {
// 		     doubleVector.push_back(floatRandomDistribution(randomEngine));
// 	    }
// 
// 	    DoubleVariableLengthVector secondVariableLengthVector(doubleVector);
// 
// 	    target.WriteAggregate(secondVariableLengthVector);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondVariableLengthVector);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatVariableLengthVector thirdVariableLengthVector;
// 
// 	    source.ReadAggregate(thirdVariableLengthVector);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdVariableLengthVector);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstVariableLengthVector, thirdVariableLengthVector,1e-8f));
// 
// 	    DoubleVariableLengthVector fourthVariableLengthVector; 
// 
// 	    source.ReadAggregate(fourthVariableLengthVector);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthVariableLengthVector);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondVariableLengthVector, fourthVariableLengthVector, 1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::PlaneTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatPlane()) + MATHEMATICS_STREAM_SIZE(DoublePlane());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatPlane firstPlane{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstPlane);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstPlane);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoublePlane secondPlane{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondPlane);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondPlane);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatPlane thirdPlane;
// 
// 	    source.ReadAggregate(thirdPlane);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdPlane);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstPlane, thirdPlane, 1e-8f));
// 
// 	    DoublePlane fourthPlane;
// 
// 	    source.ReadAggregate(fourthPlane);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthPlane);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondPlane, fourthPlane,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::PolynomialTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	uniform_int<> intRandomDistribution{ 1,20 };
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 	    int firstLength = intRandomDistribution(randomEngine);
// 	    int secondLength = intRandomDistribution(randomEngine);
// 		
// 		int maxSize = MATHEMATICS_STREAM_SIZE(FloatPolynomial(firstLength)) + MATHEMATICS_STREAM_SIZE(DoublePolynomial(secondLength));
// 
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 		int currentWriteBufferSize{ 0 };
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    vector<float> floatVector;
// 	    for(int k = 0;k <= firstLength;++k)
// 	    {
// 		     floatVector.push_back(floatRandomDistribution(randomEngine));
// 	    }
// 
// 	    FloatPolynomial firstPolynomial(floatVector);
// 
// 	    target.WriteAggregate(firstPolynomial);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstPolynomial);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    vector<double> doubleVector;
// 	    for(int k = 0;k <= secondLength;++k)
// 	    {
// 		     doubleVector.push_back(floatRandomDistribution(randomEngine));
// 	    }
// 
// 	    DoublePolynomial secondPolynomial(doubleVector);
// 
// 	    target.WriteAggregate(secondPolynomial);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondPolynomial);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatPolynomial thirdPolynomial;
// 
// 	    source.ReadAggregate(thirdPolynomial);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdPolynomial);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstPolynomial, thirdPolynomial,1e-8f));
// 
// 	    DoublePolynomial fourthPolynomial; 
// 
// 	    source.ReadAggregate(fourthPolynomial);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthPolynomial);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondPolynomial, fourthPolynomial,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Matrix2Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatMatrix2()) + MATHEMATICS_STREAM_SIZE(DoubleMatrix2());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatMatrix2 firstMatrix{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleMatrix2 secondMatrix{ doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine),doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 		int currentReadBufferSize{ 0 };
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatMatrix2 thirdMatrix;
// 
// 	    source.ReadAggregate(thirdMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix,1e-8f));
// 
// 	    DoubleMatrix2 fourthMatrix;
// 
// 	    source.ReadAggregate(fourthMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondMatrix, fourthMatrix,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Matrix3Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatMatrix3()) + MATHEMATICS_STREAM_SIZE(DoubleMatrix3());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatMatrix3 firstMatrix{ floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine),floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleMatrix3 secondMatrix{ doubleRandomDistribution(randomEngine), doubleRandomDistribution(randomEngine), doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine), doubleRandomDistribution(randomEngine), doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine), doubleRandomDistribution(randomEngine), doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatMatrix3 thirdMatrix;
// 
// 	    source.ReadAggregate(thirdMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix,1e-8f));
// 
// 	    DoubleMatrix3 fourthMatrix;
// 
// 	    source.ReadAggregate(fourthMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondMatrix, fourthMatrix,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Matrix4Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatMatrix4()) + MATHEMATICS_STREAM_SIZE(DoubleMatrix4());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 		CoreTools::BufferTarget target{ fileBufferPtr,objectRegister };
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatMatrix4 firstMatrix{ floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine),
// 							  floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleMatrix4 secondMatrix{ doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine),
// 							   doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 		CoreTools::BufferSource source{ fileBufferPtr };
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatMatrix4 thirdMatrix;
// 
// 	    source.ReadAggregate(thirdMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix,1e-8f));
// 
// 	    DoubleMatrix4 fourthMatrix;
// 
// 	    source.ReadAggregate(fourthMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondMatrix, fourthMatrix,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::MatrixTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatMatrix()) + MATHEMATICS_STREAM_SIZE(DoubleMatrix());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 		FloatMatrix firstMatrix{ floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine),
// 							 floatRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(firstMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 		DoubleMatrix secondMatrix{ doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine),
// 							  doubleRandomDistribution(randomEngine) };
// 
// 	    target.WriteAggregate(secondMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatMatrix thirdMatrix;
// 
// 	    source.ReadAggregate(thirdMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix,  1e-8f));
// 
// 	    DoubleMatrix fourthMatrix;
// 
// 	    source.ReadAggregate(fourthMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondMatrix, fourthMatrix, 1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::VariableMatrixTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	uniform_int<> intRandomDistribution{ 1,20 };
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 	    int firstLength = intRandomDistribution(randomEngine);
// 	    int secondLength = intRandomDistribution(randomEngine);
// 	    int thirdLength = intRandomDistribution(randomEngine);
// 	    int fourthLength = intRandomDistribution(randomEngine);
// 
// 	    int maxSize = MATHEMATICS_STREAM_SIZE(FloatVariableMatrix(firstLength, secondLength)) + 
// 	                  MATHEMATICS_STREAM_SIZE(DoubleVariableMatrix(thirdLength, fourthLength));
// 
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    vector<float> floatVector;
// 	    for(int k = 0;k < firstLength * secondLength;++k)
// 	    {
// 		     floatVector.push_back(floatRandomDistribution(randomEngine));
// 	    }
// 
// 	    FloatVariableMatrix firstVariableMatrix(firstLength , secondLength,floatVector);
// 
// 	    target.WriteAggregate(firstVariableMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstVariableMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    vector<double> doubleVector;
// 	    for(int k = 0;k < thirdLength * fourthLength;++k)
// 	    {
// 		     doubleVector.push_back(doubleRandomDistribution(randomEngine));
// 	    }
// 
// 	    DoubleVariableMatrix secondVariableMatrix(thirdLength , fourthLength,doubleVector);
// 
// 	    target.WriteAggregate(secondVariableMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondVariableMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatVariableMatrix thirdVariableMatrix;
// 
// 	    source.ReadAggregate(thirdVariableMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdVariableMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstVariableMatrix, thirdVariableMatrix,1e-8f));
// 
// 	    DoubleVariableMatrix fourthVariableMatrix; 
// 
// 	    source.ReadAggregate(fourthVariableMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthVariableMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondVariableMatrix, fourthVariableMatrix,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::BandedMatrixTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	uniform_int<> firstIntRandomDistribution{ 2,20 };
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 	    int firstLength = firstIntRandomDistribution(randomEngine);
// 	    int secondLength = firstIntRandomDistribution(randomEngine);
// 
// 		uniform_int<> secondIntegerRandomDistribution{ 0,firstLength - 1 };
// 
// 		uniform_int<> thirdIntegerRandomDistribution{ 0,secondLength - 1 };
// 
// 	    int thirdLength = secondIntegerRandomDistribution(randomEngine);
// 	    int fourthLength = secondIntegerRandomDistribution(randomEngine);
// 	    int fifthLength = thirdIntegerRandomDistribution(randomEngine);
// 	    int sixthLength = thirdIntegerRandomDistribution(randomEngine);
// 
// 		int maxSize = MATHEMATICS_STREAM_SIZE(DoubleBandedMatrix(firstLength, thirdLength,fourthLength)) + 
// 	                  MATHEMATICS_STREAM_SIZE(FloatBandedMatrix(secondLength, fifthLength,sixthLength));
// 
// 
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    DoubleBandedMatrix firstBandedMatrix(firstLength,thirdLength,fourthLength);
// 
// 	    // ∂‘Ω«œﬂ
// 	    for(int k = 0;k < firstBandedMatrix.GetSize();++k)
// 	    {
// 		     firstBandedMatrix(k,k) = doubleRandomDistribution(randomEngine);
// 	    }
// 
// 	    // œ¬»˝Ω«∫Õ…œ»˝Ω«
// 	    for(int row = 0;row < firstBandedMatrix.GetSize();++row)
// 	    {
// 		    for(int column = 0;column < firstBandedMatrix.GetSize();++column)
// 		    {
// 			    int band = column - row;
// 			    if(band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
// 			    {
// 				    firstBandedMatrix(row,column) = doubleRandomDistribution(randomEngine);
// 			    }
// 
// 			    if(0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
// 			    {
// 				    firstBandedMatrix(row,column) = doubleRandomDistribution(randomEngine);
// 			    }
// 		    }
// 	    }
// 
// 	    target.WriteAggregate(firstBandedMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstBandedMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    FloatBandedMatrix secondBandedMatrix(secondLength,fifthLength,sixthLength);
// 
// 	    // ∂‘Ω«œﬂ
// 	    for(int k = 0;k < secondBandedMatrix.GetSize();++k)
// 	    {
// 		    secondBandedMatrix(k,k) = floatRandomDistribution(randomEngine);
// 	    }
// 
// 	    // œ¬»˝Ω«∫Õ…œ»˝Ω«
// 	    for(int row = 0;row < secondBandedMatrix.GetSize();++row)
// 	    {
// 		    for(int column = 0;column < secondBandedMatrix.GetSize();++column)
// 		    {
// 			    int band = column - row;
// 			    if(band < 0 && -band - 1 < secondBandedMatrix.GetLowerBandsNumber())
// 			    {
// 				    secondBandedMatrix(row,column) = floatRandomDistribution(randomEngine);
// 			    }
// 
// 			    if(0 < band && band - 1 < secondBandedMatrix.GetUpperBandsNumber())
// 			    {
// 				    secondBandedMatrix(row,column) = floatRandomDistribution(randomEngine);
// 			    }
// 		    }
// 	    }
// 
// 	    target.WriteAggregate(secondBandedMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondBandedMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    DoubleBandedMatrix thirdBandedMatrix(1,0,0);
// 
// 	    source.ReadAggregate(thirdBandedMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdBandedMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstBandedMatrix.ToVariableMatrix(),  thirdBandedMatrix.ToVariableMatrix(), 1e-10));
// 
// 	    FloatBandedMatrix fourthBandedMatrix(1,0,0);
// 
// 	    source.ReadAggregate(fourthBandedMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthBandedMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondBandedMatrix.ToVariableMatrix(), fourthBandedMatrix.ToVariableMatrix(),1e-8f));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());	
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::BandedMatrixSolveTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	uniform_int<> firstIntRandomDistribution{ 2,20 };
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 	    int firstLength = firstIntRandomDistribution(randomEngine);
// 	    int secondLength = firstIntRandomDistribution(randomEngine);
// 
// 		uniform_int<> secondIntegerRandomDistribution(0,firstLength - 1);
// 
// 		uniform_int<> thirdIntegerRandomDistribution(0,secondLength - 1);
// 
// 	    int thirdLength = secondIntegerRandomDistribution(randomEngine);
// 	    int fourthLength = secondIntegerRandomDistribution(randomEngine);
// 	    int fifthLength = thirdIntegerRandomDistribution(randomEngine);
// 	    int sixthLength = thirdIntegerRandomDistribution(randomEngine);
// 
// 		int maxSize = MATHEMATICS_STREAM_SIZE(DoubleBandedMatrixSolve(firstLength, thirdLength,fourthLength)) + 
// 	                  MATHEMATICS_STREAM_SIZE(FloatBandedMatrixSolve(secondLength, fifthLength,sixthLength));
// 
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    DoubleBandedMatrixSolve firstBandedMatrix(firstLength,thirdLength,fourthLength);
// 
// 	    // ∂‘Ω«œﬂ
// 	    for(int k = 0;k < firstBandedMatrix.GetSize();++k)
// 	    {
// 		    firstBandedMatrix(k,k) = doubleRandomDistribution(randomEngine);
// 	    }
// 
// 	    // œ¬»˝Ω«∫Õ…œ»˝Ω«
// 	    for(int row = 0;row < firstBandedMatrix.GetSize();++row)
// 	    {
// 		    for(int column = 0;column < firstBandedMatrix.GetSize();++column)
// 		    {
// 			    int band = column - row;
// 			    if(band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
// 			    {
// 				    firstBandedMatrix(row,column) = doubleRandomDistribution(randomEngine);
// 			    }
// 
// 			    if(0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
// 			    {
// 				    firstBandedMatrix(row,column) = doubleRandomDistribution(randomEngine);
// 			    }
// 		    }
// 	    }
// 
// 	    target.WriteAggregate(firstBandedMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstBandedMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    FloatBandedMatrixSolve secondBandedMatrix(secondLength,fifthLength,sixthLength);
// 
// 	    // ∂‘Ω«œﬂ
// 	    for(int k = 0;k < secondBandedMatrix.GetSize();++k)
// 	    {
// 		    secondBandedMatrix(k,k) = floatRandomDistribution(randomEngine);
// 	    }
// 
// 	    // œ¬»˝Ω«∫Õ…œ»˝Ω«
// 	    for(int row = 0;row < secondBandedMatrix.GetSize();++row)
// 	    {
// 		    for(int column = 0;column < secondBandedMatrix.GetSize();++column)
// 		    {
// 			    int band = column - row;
// 			    if(band < 0 && -band - 1 < secondBandedMatrix.GetLowerBandsNumber())
// 			    {
// 				    secondBandedMatrix(row,column) = floatRandomDistribution(randomEngine);
// 			    }
// 
// 			    if(0 < band && band - 1 < secondBandedMatrix.GetUpperBandsNumber())
// 			    {
// 				    secondBandedMatrix(row,column) = floatRandomDistribution(randomEngine);
// 			    }
// 		    }
// 	    }
// 
// 	    target.WriteAggregate(secondBandedMatrix);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondBandedMatrix);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    DoubleBandedMatrixSolve thirdBandedMatrix(1,0,0);
// 
// 	    source.ReadAggregate(thirdBandedMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdBandedMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstBandedMatrix.ToInputVariableMatrix(), thirdBandedMatrix.ToInputVariableMatrix(), 1e-10));
// 
// 	    FloatBandedMatrixSolve fourthBandedMatrix(1,0,0);
// 
// 	    source.ReadAggregate(fourthBandedMatrix);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthBandedMatrix);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondBandedMatrix.ToInputVariableMatrix(), fourthBandedMatrix.ToInputVariableMatrix(),1e-8f));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());	
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::QuaternionTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatAQuaternion()) +   MATHEMATICS_STREAM_SIZE(DoubleAQuaternion());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    FloatQuaternion firstQuaternion(floatRandomDistribution(randomEngine),
// 			                        floatRandomDistribution(randomEngine),
// 			                        floatRandomDistribution(randomEngine),
// 			                        floatRandomDistribution(randomEngine));
// 
// 	    target.WriteAggregate(firstQuaternion);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstQuaternion);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    DoubleQuaternion secondQuaternion(doubleRandomDistribution(randomEngine),
// 			                         doubleRandomDistribution(randomEngine),
// 			                         doubleRandomDistribution(randomEngine),
// 			                         doubleRandomDistribution(randomEngine));
//       
// 	    target.WriteAggregate(secondQuaternion);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondQuaternion);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatQuaternion thirdQuaternion;
// 
// 	    source.ReadAggregate(thirdQuaternion);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdQuaternion);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstQuaternion, thirdQuaternion, 1e-8f));
// 
// 	    DoubleQuaternion fourthQuaternion;
// 
// 	    source.ReadAggregate(fourthQuaternion);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthQuaternion);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondQuaternion, fourthQuaternion,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::AQuaternionTest()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 	uniform_real<double> doubleRandomDistribution{ -10.0,10.0 };
// 	int maxSize = MATHEMATICS_STREAM_SIZE(FloatAQuaternion()) +   MATHEMATICS_STREAM_SIZE(DoubleAQuaternion());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    FloatAQuaternion firstAQuaternion(floatRandomDistribution(randomEngine),
// 			                          floatRandomDistribution(randomEngine),
// 			                          floatRandomDistribution(randomEngine),
// 			                          floatRandomDistribution(randomEngine));
// 
// 	    target.WriteAggregate(firstAQuaternion);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstAQuaternion);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    DoubleAQuaternion secondAQuaternion(doubleRandomDistribution(randomEngine),
// 			                           doubleRandomDistribution(randomEngine),
// 			                           doubleRandomDistribution(randomEngine),
// 			                           doubleRandomDistribution(randomEngine));
//       
// 	    target.WriteAggregate(secondAQuaternion);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(secondAQuaternion);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    FloatAQuaternion thirdAQuaternion;
// 
// 	    source.ReadAggregate(thirdAQuaternion);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(thirdAQuaternion);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstAQuaternion, thirdAQuaternion, 1e-8f));
// 
// 	    DoubleAQuaternion fourthAQuaternion;
// 
// 	    source.ReadAggregate(fourthAQuaternion);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(fourthAQuaternion);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(secondAQuaternion, fourthAQuaternion,1e-10));
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Float1Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f }; 
// 
// 	int maxSize = MATHEMATICS_STREAM_SIZE(Float1());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Float1 firstFloat(floatRandomDistribution(randomEngine));
// 
// 	    target.WriteAggregate(firstFloat);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstFloat);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Float1 secondFloat;
// 
// 	    source.ReadAggregate(secondFloat);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(secondFloat);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_APPROXIMATE(firstFloat.GetValue(), secondFloat.GetValue(),  1e-8f);	   
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Float2Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 
// 	int maxSize = MATHEMATICS_STREAM_SIZE(Float2());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Float2 firstFloat(floatRandomDistribution(randomEngine),  floatRandomDistribution(randomEngine));
// 
// 	    target.WriteAggregate(firstFloat);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstFloat);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Float2 secondFloat;
// 
// 	    source.ReadAggregate(secondFloat);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(secondFloat);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_APPROXIMATE(firstFloat.GetFirstValue(), secondFloat.GetFirstValue(), 1e-8f);
// 	    ASSERT_APPROXIMATE(firstFloat.GetSecondValue(), secondFloat.GetSecondValue(),1e-8f);	 	   
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Float3Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 
// 	int maxSize = MATHEMATICS_STREAM_SIZE(Float3());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Float3 firstFloat(floatRandomDistribution(randomEngine),
//                           floatRandomDistribution(randomEngine),
//                           floatRandomDistribution(randomEngine));
// 
// 	    target.WriteAggregate(firstFloat);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstFloat);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Float3 secondFloat;
// 
// 	    source.ReadAggregate(secondFloat);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(secondFloat);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_APPROXIMATE(firstFloat.GetFirstValue(), secondFloat.GetFirstValue(),  1e-8f);
// 	    ASSERT_APPROXIMATE(firstFloat.GetSecondValue(), secondFloat.GetSecondValue(),  1e-8f);	
// 	    ASSERT_APPROXIMATE(firstFloat.GetThirdValue(), secondFloat.GetThirdValue(),  1e-8f); 	   
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 
// 	}
}

void Mathematics::AlgebraAggregateTesting
	::Float4Test()
{
// 	default_random_engine randomEngine{};
// 	uniform_real<float> floatRandomDistribution{ -10.0f,10.0f };
// 
// 	int maxSize = MATHEMATICS_STREAM_SIZE(Float4());
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto loop = 0; loop < testLoopCount; ++loop)
// 	{
// 		CoreTools::BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<CoreTools::FileBuffer>(maxSize) };
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Float4 firstFloat(floatRandomDistribution(randomEngine),
//                           floatRandomDistribution(randomEngine),
//                           floatRandomDistribution(randomEngine),
//                           floatRandomDistribution(randomEngine));
// 
// 	    target.WriteAggregate(firstFloat);
// 
// 	    currentWriteBufferSize += MATHEMATICS_STREAM_SIZE(firstFloat);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Float4 secondFloat;
// 
// 	    source.ReadAggregate(secondFloat);
// 
// 	    currentReadBufferSize += MATHEMATICS_STREAM_SIZE(secondFloat);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_APPROXIMATE(firstFloat.GetFirstValue(), secondFloat.GetFirstValue(),1e-8f);
// 	    ASSERT_APPROXIMATE(firstFloat.GetSecondValue(), secondFloat.GetSecondValue(),  1e-8f);	
// 	    ASSERT_APPROXIMATE(firstFloat.GetThirdValue(), secondFloat.GetThirdValue(),  1e-8f);   
// 	    ASSERT_APPROXIMATE(firstFloat.GetFourthValue(), secondFloat.GetFourthValue(),  1e-8f);	   
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}
}