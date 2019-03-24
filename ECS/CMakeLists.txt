set(SOURCES src/Event.cpp
            src/Component.cpp
            src/Entity.cpp
            src/System.cpp

            src/ComponentManager.cpp
            src/EntityManager.cpp
            src/SystemManager.cpp
            src/ECS.cpp)

add_library(ECS STATIC ${SOURCES})

