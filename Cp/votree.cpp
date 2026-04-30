#include <iostream>
#include <vector>
struct Pose {
   float position[3];
   float rotation[4]; // Quaternion
};
class AnimationClip {
public:
   std::vector<Pose> poses;
   float duration;
   Pose getPoseAtTime(float time) {
       // Simple linear interpolation between poses
       int index = static_cast<int>((time / duration) * poses.size());
       return poses[index % poses.size()];
   }
};
class Animator {
public:
   AnimationClip* currentClip;
   float currentTime;
   void update(float deltaTime) {
       if (currentClip) {
           currentTime += deltaTime;
           Pose pose = currentClip->getPoseAtTime(currentTime);
           applyPose(pose);
       }
   }
   void applyPose(const Pose& pose) {
       // Apply the pose to the character's skeleton
       std::cout << "Applying pose: Position(" << pose.position[0] << ", " << pose.position[1] << ", " << pose.position[2] << ")\n";
   }
};
int main() {
   AnimationClip walkClip;
   walkClip.duration = 1.0f;
   walkClip.poses = { {{0, 0, 0}, {0, 0, 0, 1}}, {{1, 0, 0}, {0, 0, 0, 1}} };
   Animator animator;
   animator.currentClip = &walkClip;
   for (int i = 0; i < 10; ++i) {
       animator.update(0.1f);
   }
   return 0;
}