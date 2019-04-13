#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <memory>
#include <unordered_map>

#include "IEntity.hpp"

namespace ecs
{
    using Entity_Ptr = std::unique_ptr<IEntity>;

    class EntityManager
    {
        public:
            EntityManager() : entity_id_(0) {}

            template<typename T>
            T* GetEntity(EntityId entityid)
            {
                auto it = entities_.find(entityid);

                return it != entities_.end()
                        ? (T*)it->second.get()
                        : nullptr;
            }

            template<typename T, typename... ARGS>
            T* CreateEntity(ARGS&&... args)
            {
                EntityId entityid = ++entity_id_;

                IEntity* entity = new T(std::forward<ARGS>(args)...);
                entity->entityid_ = entityid;
                
                entities_[entityid] = Entity_Ptr(entity);

                return static_cast<T*>(entity);
            }

            template<typename T>
            void DestroyEntity(EntityId entityid)
            {
                auto it = entities_.find(entityid);

                if(it != entities_.end() )
                {
                    entities_.erase(it);
                }
            }

            void DestroyAllEntities()
            {
                entities_.clear();
            }

        private:
            size_t entity_id_;

            std::unordered_map<EntityId, Entity_Ptr> entities_;
    };
}

#endif // ENTITY_MANAGER_HPP
