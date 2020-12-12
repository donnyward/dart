#include "dart-c.h"

#include "dart.hpp"

struct Context
{
    dart::simulation::World* world = nullptr;
    int nextMultibodyId = 1;

    dart::dynamics::SkeletonPtr testSkeleton = nullptr;
};
Context* g_Context = {};

int dartcCreateMultibody(
    float offsetX,
    float offsetY,
    float offsetZ)
{
    dart::dynamics::SkeletonPtr skeleton = dart::dynamics::Skeleton::create("Generic Player");
    
    //root body
    auto pair = skeleton->createJointAndBodyNodePair<dart::dynamics::FreeJoint>(nullptr);
    dart::dynamics::JointPtr joint = pair.first;
    dart::dynamics::BodyNodePtr body = pair.second;

    dart::dynamics::BoxShapePtr boxShape = std::make_shared<dart::dynamics::BoxShape>(
        Eigen::Vector3d(
            1,
            1,
            1));
            /*mbInfo.BoneInfo[0].HalfExtents.x * 2,
            mbInfo.BoneInfo[0].HalfExtents.y * 2,
            mbInfo.BoneInfo[0].HalfExtents.z * 2));
            */
    body->createShapeNodeWith<dart::dynamics::CollisionAspect, dart::dynamics::DynamicsAspect>(boxShape);

    dart::dynamics::Inertia inertia;
    double mass = 10;
    inertia.setMass(mass);
    inertia.setMoment(boxShape->computeInertia(mass));
    body->setInertia(inertia);

    // Set the starting position for the root body
    Eigen::Vector6d positions(Eigen::Vector6d::Zero());
    positions[5] = 10;
    joint->setPositions(positions);

    //2nd
    auto childPair = skeleton->createJointAndBodyNodePair<dart::dynamics::BallJoint>(body);
    dart::dynamics::JointPtr childJoint = childPair.first;
    dart::dynamics::BodyNodePtr childBody = childPair.second;

    dart::dynamics::BoxShapePtr childBoxShape = std::make_shared<dart::dynamics::BoxShape>(
        Eigen::Vector3d(
            1,
            1,
            1));
    /*mbInfo.BoneInfo[0].HalfExtents.x * 2,
      mbInfo.BoneInfo[0].HalfExtents.y * 2,
      mbInfo.BoneInfo[0].HalfExtents.z * 2));
    */
    childBody->createShapeNodeWith<dart::dynamics::CollisionAspect, dart::dynamics::DynamicsAspect>(boxShape);
    childBody->setInertia(inertia);

    // Set the starting position for the body
    //Eigen::Vector6d positions(Eigen::Vector6d::Zero());
    //positions[5] = 10;
    //joint->setPositions(positions);
    Eigen::Isometry3d xform(Eigen::Isometry3d::Identity());
    xform.translation() = Eigen::Vector3d(
        1,
        0,
        1);
    childJoint->setTransformFromParentBodyNode(xform);
    childJoint->setTransformFromChildBodyNode(xform.inverse());

    g_Context->world->addSkeleton(skeleton);
    g_Context->testSkeleton = skeleton;
    return 1;
}

void dartcCreateStaticBox(
    float lengthX,
    float lengthY,
    float lengthZ,
    float posX,
    float posY,
    float posZ)
{
    dart::dynamics::SkeletonPtr skeleton = dart::dynamics::Skeleton::create("box");

    auto pair = skeleton->createJointAndBodyNodePair<dart::dynamics::WeldJoint>();
    dart::dynamics::JointPtr joint = pair.first;
    dart::dynamics::BodyNodePtr body = pair.second;

    std::shared_ptr<dart::dynamics::BoxShape> shape = std::make_shared<dart::dynamics::BoxShape>(
        Eigen::Vector3d(lengthX, lengthY, lengthZ));
    auto shapeNode
        = body->createShapeNodeWith<dart::dynamics::CollisionAspect, dart::dynamics::DynamicsAspect>(shape);

    Eigen::Isometry3d xform(Eigen::Isometry3d::Identity());
    xform.translation() = Eigen::Vector3d(
        posX,
        posY,
        posZ);
    joint->setTransformFromParentBodyNode(xform);

    g_Context->world->addSkeleton(skeleton);
}

void dartcCreatePhysicsWorld()
{
    g_Context = new Context;
    g_Context->world = new dart::simulation::World;
}

void dartcDestroyPhysicsWorld()
{
    if (g_Context && g_Context->world)
    {
        delete g_Context->world;
        g_Context->world = nullptr;
    }
    delete g_Context;
    g_Context = nullptr;
}

dartcState dartcGetState(int multibodyId)
{
    dartcState st;
    Eigen::VectorXd pos = g_Context->testSkeleton->getPositions();
    st.x1= pos(3);
    st.y1= pos(4);
    st.z1= pos(5);

    st.angx1 = pos(6);
    st.angy1 = pos(7);
    st.angz1 = pos(8);
    return st;
}

void dartcSetTimestep(float seconds)
{
    if (g_Context && g_Context->world)
    {
        g_Context->world->setTimeStep(seconds);
    }
}

void dartcStepWorld()
{
    g_Context->world->step();
}

