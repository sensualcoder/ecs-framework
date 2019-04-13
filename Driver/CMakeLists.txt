include_directories(${PROJECT_SOURCE_DIR}/ECS/include)
include_directories(include)

set(SOURCES src/AttackComponent.cpp
            src/Attacker.cpp
            src/BattleScene.cpp
            src/BattleSystem.cpp
            src/CombatEntity.cpp
            src/Driver.cpp)

add_library(Driver STATIC ${SOURCES})
target_link_libraries(Driver)