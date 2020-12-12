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

    g_Context->world->addSkeleton(skeleton);
    g_Context->testSkeleton = skeleton;
    return 1;
}

void dartcCreatePhysicsWorld()
{
    g_Context = new Context;
    g_Context->world = new dart::simulation::World;
}

float dartcDartCTest()
{
    Eigen::VectorXd pos = g_Context->testSkeleton->getPositions();
    return pos(5);
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

void dartcStepWorld(float seconds)
{
    if (g_Context && g_Context->world)
    {
        //TODO don't do this every step...
        g_Context->world->setTimeStep(seconds);

        g_Context->world->step();
    }
}

