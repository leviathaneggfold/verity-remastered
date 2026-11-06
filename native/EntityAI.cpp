#include <iostream>
#include <vector>
#include <cmath>
#include <random>

namespace VerityAI {

    struct Vec3 {
        float x, y, z;
        Vec3 operator-(const Vec3& other) const {
            return {x - other.x, y - other.y, z - other.z};
        }
        float length() const {
            return std::sqrt(x*x + y*y + z*z);
        }
    };

    enum class EntityState {
        IDLE,
        PATROL,
        CHASE,
        HIDE,
        ATTACK
    };

    class VerityEntity {
    private:
        Vec3 position;
        Vec3 targetPosition;
        EntityState currentState;
        float aggroRange;
        float attackRange;
        float speed;

    public:
        VerityEntity() : currentState(EntityState::IDLE), aggroRange(20.0f), attackRange(2.5f), speed(0.35f) {
            position = {0.0f, 64.0f, 0.0f};
        }

        void update(Vec3 playerPos) {
            float distanceToPlayer = (playerPos - position).length();

            switch (currentState) {
                case EntityState::IDLE:
                    if (distanceToPlayer < aggroRange) {
                        currentState = EntityState::CHASE;
                        std::cout << "[AI] Player detected! Initiating chase." << std::endl;
                    }
                    break;
                case EntityState::CHASE:
                    targetPosition = playerPos;
                    moveTowardsTarget();
                    if (distanceToPlayer < attackRange) {
                        currentState = EntityState::ATTACK;
                        executeAttack();
                    } else if (distanceToPlayer > aggroRange * 1.5f) {
                        currentState = EntityState::PATROL;
                    }
                    break;
                case EntityState::ATTACK:
                    // Attack animation and damage logic
                    std::cout << "[AI] Attacking player!" << std::endl;
                    currentState = EntityState::CHASE;
                    break;
                default:
                    break;
            }
        }

        void moveTowardsTarget() {
            Vec3 direction = targetPosition - position;
            float dist = direction.length();
            if (dist > 0) {
                position.x += (direction.x / dist) * speed;
                position.y += (direction.y / dist) * speed;
                position.z += (direction.z / dist) * speed;
            }
        }

        void executeAttack() {
            // Play scary sound
            // Apply damage
        }
    };
}
